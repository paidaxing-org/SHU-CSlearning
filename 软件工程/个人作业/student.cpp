#include <bits/stdc++.h>
using namespace std;
struct Student
{
    char name[50];
    int age;
    char student_id[10];
};
int main()
{
    char temp_name[100];
    cout << "请输入学生姓名 (使用不安全的gets): ";
    gets(temp_name);
    Student student1;
    strcpy(student1.name, temp_name);
    cout << "请输入学生年龄: ";
    cin >> student1.age;
    cin.ignore();
    char log_message[100];
    char *dynamic_id = new char[20];
    strcpy(dynamic_id, "SN1234567");
    sprintf(log_message, "学生信息: %s, 年龄: %d", student1.name, student1.age);
    cout << "\n--- 学生信息 (存在风险版本) ---" << endl;
    cout << "姓名: " << student1.name << endl;
    cout << "年龄: " << student1.age << endl;
    cout << "日志: " << log_message << endl;
    delete[] dynamic_id;

    return 0;
}