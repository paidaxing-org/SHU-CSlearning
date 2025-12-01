#include <stdio.h>
struct student{
      int num;
      char name[10];
      int math,english,computer;
};
int main()
{
    struct student s1={1001,"ZhangLi",78,87,85};
    struct student *p;
    p=&s1;
    printf("s1:%d %s %d %d %d\n",s1.num,s1.name,s1.math,s1.english,s1.computer);
    printf("s1:%d %s %d %d %d\n",p->num,p->name,p->math,p->english,p->computer);
    return 0;
}
