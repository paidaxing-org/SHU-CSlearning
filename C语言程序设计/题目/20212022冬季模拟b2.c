#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,s=0,geshu=0;
    char a[20];
    gets(a);
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]>='0'&&a[i]<='9')
            s=s+1;
        else if(a[i]=='.')
        {
            s=s+1;
            geshu=geshu+1;
        }
        else
            break;
        if(geshu==2)
            break;
    }
    if(i!=strlen(a)&&geshu!=2)
        printf("Error %d",s);
    else if(i!=strlen(a)&&geshu==2)
        printf("Error %d",s-2);
    else
        printf("Yes");
    return 0;
}
