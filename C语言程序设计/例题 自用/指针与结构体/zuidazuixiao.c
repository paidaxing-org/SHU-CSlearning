#include <stdio.h>
#include <string.h>
void paixu(char *color[],int n)
{
    int k,j;
    char *temp;
    for(k=1;k<n;k++)
        for(j=0;j<n-k;j++)
            if(strcmp(color[j],color[j+1])>0)
            {
                    temp=color[j];
                    color[j]=color[j+1];
                    color[j+1]=temp;
            }
}
int main()
{
    int i;
    char *p[]={"red","blue","yellow","green","purple"};
    paixu(p,5);
    for(i=0;i<5;i++)
        printf("%s ",p[i]);
    return 0;
}
