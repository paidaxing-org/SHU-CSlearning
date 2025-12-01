#include <stdio.h>
#include <string.h>
int main()
{
    char a[20],b[20];
    char temp;
    gets(a);
    int i,j=0,s=0;
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]=='c')
        {
            s=s+1;
        }
        else
        {
            b[j]=a[i];
            j++;
        }
    }
    b[j]='\0';
    if(s==0)
        printf("No c\n");
    else
        printf("count:%d\n",s);
    printf("b:");
    puts(b);
    for(i=0;i<strlen(b);i++)
        for(j=0;j<strlen(b);j++)
       {
           if(b[i]<b[j])
           {
               temp=b[i];
               b[i]=b[j];
               b[j]=temp;
           }
       }
       printf("b sorted:");
       puts(b);
    return 0;
}
