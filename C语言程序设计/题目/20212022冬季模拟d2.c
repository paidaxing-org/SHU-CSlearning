#include <stdio.h>
int main()
{
    int a[20]={0},b[20]={0};
    int i,s,j,h,n,x,ji,ou,zong;
    scanf("%d",&n);
    printf("[%d] ",n);
    a[0]=n;
    if(n>0&&n/100000000==0)
    {
        for(i=0;;i++)
         {
            ou=0;
            ji=0;
            zong=0;
            x=a[i];
           while(x!=0)
        {
            j=x%10;
            if(j%2==0)
                ou=ou+1;
            else
                ji=ji+1;
            zong=zong+1;
            x=x/10;
        }
        a[i+1]=100*ou+10*ji+zong;
        printf("{%d}%d ",i+1,a[i+1]);
        if(a[i+1]==123)
            break;
         }
    }
    else
        printf("Error");
    return 0;
}
