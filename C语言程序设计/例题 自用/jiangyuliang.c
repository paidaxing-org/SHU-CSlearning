#include <stdio.h>
int main()
{
    float a[12];
    int b[12];
    int i,j,sum=0;
    for(i=0;i<12;i++)
        scanf("%f",&a[i]);
    for(i=0;i<12;i++)
        sum=sum*1.0+a[i];
    for(i=0;i<12;i++)
        b[i]=a[i]*100/sum+0.5;
    for(i=0;i<12;i++)
    {
        printf("%d(%d%%)",i+1,b[i]);
        for(j=0;j<b[i];j++)
           printf("#");
        printf("\n");
    }
    return 0;
}
