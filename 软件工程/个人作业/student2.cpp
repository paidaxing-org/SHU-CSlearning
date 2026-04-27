#include <bits/stdc++.h>
using namespace std;
// 使用 string 替代固定长度字符数组，自动管理内存并防止越界写入
struct Student
{
    string name;       // 比较安全，不会因 strcpy 而溢出
    int age = 0;       // 初始化，避免未定义值
    string student_id; // 使用 string 来保存学号
};
int main()
{
    // 使用 string + getline 安全读取整行输入（不会写出缓冲区边界）
    string temp_name;
    cout << "请输入学生姓名：";
    getline(cin, temp_name);
    // 如果希望对姓名长度做限制，可以显式截断并记录：
    const size_t MAX_NAME_LEN = 50; // 原代码 name 缓冲区为 50
    if (temp_name.size() > MAX_NAME_LEN - 1)
    {
        // 截断以保证兼容旧有定长存储限制（如果需要的话），并告知用户
        temp_name = temp_name.substr(0, MAX_NAME_LEN - 1);
        cout << "警告：姓名过长，已被截断到 " << (MAX_NAME_LEN - 1) << " 个字符。\n";
    }
    Student student1;
    student1.name = temp_name; // 安全赋值，无溢出
    // 读取年龄：使用 getline 然后验证，避免直接用 >> 导致输入残留或格式错误
    cout << "请输入学生年龄：";
    string age_line;
    getline(cin, age_line);
    // 验证年龄为正整数且在合理范围内
    try
    {
        // 使用 stoi 解析并检查范围
        long parsed = stol(age_line);
        if (parsed < 0 || parsed > 150)
        {
            cerr << "无效的年龄范围，设置为 0。\n";
            student1.age = 0;
        }
        else
            student1.age = static_cast<int>(parsed);
    }
    catch (const exception &e)
    {
        // 解析失败时使用默认值并告知
        cerr << "年龄输入解析失败，已设置为 0。\n";
        student1.age = 0;
    }
    // 学号示例：使用 string 而不是 new char[]，避免手动管理内存
    string dynamic_id = "SN1234567"; // 更安全，也更简洁
    // 如果我们需要强制学号长度（原来 student_id 是 10 字节），可以截断或校验：
    const size_t MAX_ID_LEN = 10;
    if (dynamic_id.size() > MAX_ID_LEN - 1)
        dynamic_id = dynamic_id.substr(0, MAX_ID_LEN - 1);
    student1.student_id = dynamic_id;
    // 构建日志信息：使用 ostringstream 或 snprintf 的安全版本，避免 sprintf 导致溢出
    ostringstream oss;
    oss << "学生信息: " << student1.name << ", 年龄: " << student1.age;
    string log_message = oss.str(); // 安全的字符串构造
    cout << "\n--- 学生信息 (修正版) ---" << endl;
    cout << "姓名: " << student1.name << endl;
    cout << "年龄: " << student1.age << endl;
    cout << "学号: " << student1.student_id << endl;
    cout << "日志: " << log_message << endl;
    // 不需要显式 delete，所有对象在离开作用域时自动清理（RAII）
    return 0;
}