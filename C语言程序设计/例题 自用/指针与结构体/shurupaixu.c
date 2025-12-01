#include <stdio.h>
void shuru(int a[])
{
    int i;
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
}
void paixu(int a[])
{
    int i,j,temp;
    for(i=0;i<9;i++)
        for(j=0;j<9-i;j++)
        {
           if(a[j]>=a[j+1])
           {
               temp=a[j];
               a[j]=a[j+1];
               a[j+1]=temp;
           }
        }
}
void shuchu(int a[])
{
    int i;
    for(i=0;i<10;i++)
        printf("%d ",a[i]);

}
int main()
{
    int a[20];
    shuru(a);
    paixu(a);
    shuchu(a);
    return 0;
}
