#include <stdio.h>
int main()
{
    int N,t,i,j;
    printf("Input length (N<=100):");
    scanf("%d",&N);
    int a[100]={0};
    for(i=0;i<N;i++)
        scanf("%d",&a[i]);
    for(i=1;i<N;i++)
        for(j=0;j<N-1;j++)
           if(a[j]<a[j+1])
           {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
           }
           printf("The max is %d\n",a[0]);
           printf("The min is %d",a[N-1]);
    return 0;
}
