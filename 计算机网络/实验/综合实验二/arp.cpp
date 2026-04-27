#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>
#include <atomic>
#include <ctime>
#ifdef HAVE_PCAP
#include <pcap.h>
#include <netinet/if_ether.h>
#endif
std::mutex out_mtx;
std::atomic<bool> running(true);
std::string now_str()
{
    std::time_t t = std::time(nullptr);
    char buf[64];
    std::strftime(buf, sizeof(buf), "%F %T", std::localtime(&t));
    return std::string(buf);
}
std::map<std::string, std::string> read_arp_table()
{
    std::map<std::string, std::string> res;
    std::ifstream f("/proc/net/arp");
    if (!f.is_open())
        return res;
    std::string line;
    // skip header
    std::getline(f, line);
    while (std::getline(f, line))
    {
        std::istringstream iss(line);
        std::string ip, hw_type, flags, mac, mask, device;
        if (!(iss >> ip >> hw_type >> flags >> mac >> mask >> device))
            continue;
        res[ip] = mac;
    }
    return res;
}
void arp_table_monitor(const std::vector<std::string> &targets, int interval_seconds, const std::string &logfile)
{
    std::map<std::string, std::string> last;
    if (!targets.empty())
    {
        auto tbl = read_arp_table();
        for (const auto &t : targets)
        {
            if (tbl.count(t))
                last[t] = tbl[t];
            else
                last[t] = "UNKNOWN";
        }
    }
    std::ofstream logf;
    if (!logfile.empty())
        logf.open(logfile, std::ios::app);
    while (running)
    {
        auto tbl = read_arp_table();
        for (const auto &t : targets)
        {
            std::string cur = "UNKNOWN";
            if (tbl.count(t))
                cur = tbl[t];
            if (!last.count(t))
            {
                last[t] = cur;
                continue;
            }
            if (cur != last[t])
            {
                std::lock_guard<std::mutex> lk(out_mtx);
                std::cout << "[" << now_str() << "] ALERT: ARP mapping changed for " << t
                          << " : " << last[t] << " -> " << cur << std::endl;
                if (logf.is_open())
                {
                    logf << "[" << now_str() << "] ALERT: " << t << " : " << last[t] << " -> " << cur << "\n";
                    logf.flush();
                }
                last[t] = cur;
            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(interval_seconds));
    }
    if (logf.is_open())
        logf.close();
}
#ifdef HAVE_PCAP
std::string mac_to_str(const u_char *mac)
{
    char buf[32];
    std::sprintf(buf, "%02x:%02x:%02x:%02x:%02x:%02x",
                 mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    return std::string(buf);
}
void pcap_loop_thread(const std::string &iface, const std::string &logfile)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(iface.c_str(), BUFSIZ, 1, 1000, errbuf);
    if (!handle)
    {
        std::lock_guard<std::mutex> lk(out_mtx);
        std::cerr << "pcap_open_live failed: " << errbuf << std::endl;
        return;
    }
    struct bpf_program fp;
    if (pcap_compile(handle, &fp, "arp", 1, PCAP_NETMASK_UNKNOWN) == 0)
    {
        pcap_setfilter(handle, &fp);
        pcap_freecode(&fp);
    }

    std::ofstream logf;
    if (!logfile.empty())
        logf.open(logfile, std::ios::app);

    while (running)
    {
        struct pcap_pkthdr *header;
        const u_char *packet;
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 1 && packet)
        {
            const struct ether_header *eth = (const struct ether_header *)packet;
            if (ntohs(eth->ether_type) == ETHERTYPE_ARP)
            {
                const u_char *arp_ptr = packet + sizeof(struct ether_header);
                const u_char *sender_mac = arp_ptr + 8;
                const u_char *sender_ip = arp_ptr + 14;
                char ipbuf[16];
                std::sprintf(ipbuf, "%u.%u.%u.%u", sender_ip[0], sender_ip[1], sender_ip[2], sender_ip[3]);
                std::string macs = mac_to_str(sender_mac);
                {
                    std::lock_guard<std::mutex> lk(out_mtx);
                    std::cout << "[" << now_str() << "] OBSERVED ARP: " << ipbuf << " -> " << macs << std::endl;
                    if (logf.is_open())
                    {
                        logf << "[" << now_str() << "] OBSERVED ARP: " << ipbuf << " -> " << macs << "\n";
                        logf.flush();
                    }
                }
            }
        }
        else if (res == -1)
        {
            std::lock_guard<std::mutex> lk(out_mtx);
            std::cerr << "pcap_next_ex error: " << pcap_geterr(handle) << std::endl;
            break;
        }
    }
    if (logf.is_open())
        logf.close();
    pcap_close(handle);
}
#endif
int main(int argc, char *argv[])
{
    std::vector<std::string> targets;
    std::string iface;
    int interval = 5;
    std::string logfile = "arp_monitor.log";

    for (int i = 1; i < argc; i++)
    {
        std::string s = argv[i];
        if ((s == "-t" || s == "--target") && i + 1 < argc)
        {
            targets.push_back(argv[++i]);
        }
        else if ((s == "-i" || s == "--iface") && i + 1 < argc)
        {
            iface = argv[++i];
        }
        else if ((s == "-n" || s == "--interval") && i + 1 < argc)
        {
            interval = std::stoi(argv[++i]);
        }
        else if ((s == "-l" || s == "--log") && i + 1 < argc)
        {
            logfile = argv[++i];
        }
        else
        {
            std::cout << "Usage: " << argv[0] << " [-t ip] [-i iface] [-n interval] [-l logfile]\n";
            std::cout << "Example: sudo " << argv[0] << " -t 192.168.1.1 -i eth0 -n 3 -l out.log\n";
            return 0;
        }
    }
    std::cout << "Starting ARP monitor. Targets:";
    for (auto &t : targets)
        std::cout << " " << t;
    std::cout << " | pcap iface: " << (iface.empty() ? "(none)" : iface) << " | interval: " << interval << "s\n";
    std::thread t1;
#ifdef HAVE_PCAP
    if (!iface.empty())
    {
        t1 = std::thread(pcap_loop_thread, iface, logfile);
    }
#else
    if (!iface.empty())
    {
        std::lock_guard<std::mutex> lk(out_mtx);
        std::cerr << "Libpcap support not compiled in. Recompile with -DHAVE_PCAP and link -lpcap to enable.\n";
    }
#endif
    // Start arp table monitor in main thread
    arp_table_monitor(targets, interval, logfile);

    running = false;
    if (t1.joinable())
        t1.join();
    return 0;
}
