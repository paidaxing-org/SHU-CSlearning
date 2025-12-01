#include <stdio.h>
int main()
{
    float a[7]={0};
    float sum=0,temp,zongfen,nandu;
    int i,j;
    scanf("%f",&nandu);
    for(i=0;i<7;i++)
        scanf("%f",&a[i]);
    for(i=0;i<7;i++)
        for(j=0;j<7;j++)
            if(a[i]>=a[j])
            {
                 temp=a[i];
                 a[i]=a[j];
                 a[j]=temp;
            }
    for(i=2;i<5;i++)
        sum=sum+a[i];
    zongfen=sum*nandu;
    printf("%.2f",zongfen);
    return 0;
}
