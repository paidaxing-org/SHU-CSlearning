#include <stdio.h>
struct student{
    int num;
    char name[10];
};
void output_student(struct student students[])
{
    struct student *p;
    for(p=students;p<students+3;p++)
        printf("The number %d student's score name is %s\n",p->num,p->name);
}
int main()
{
    struct student students[3]={{1001,"ZhangLi"},{1002,"WangWu"},{1003,"LiYan"}};
    output_student(students);
    return 0;
}
