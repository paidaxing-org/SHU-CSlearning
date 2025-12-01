#include <stdio.h>
int main()
{
    int score;
    char A,B,C,D,E;
    printf("输入分数:");
    scanf("%d",&score);
    if (score>100||score<0)
        printf("输入错误!\n");
    else if (score<60)
        printf("E");
    else if (score>=60&&score<=69)
        printf("D");
    else if (score>=70&&score<=79)
        printf("C");
    else if (score>=80&&score<=89)
        printf("B");
    else if (score>=90)
        printf("A");
    return 0;
}
