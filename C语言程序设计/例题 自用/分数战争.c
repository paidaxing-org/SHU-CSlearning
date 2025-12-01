#include <stdio.h>
int main()
{
    int score[20],N,i,sum=0;
    float ave;
    scanf("%d",&N);
    for(i=0;i<N;i++)
        scanf("%d",&score[i]);
    for(i=0;i<N;i++)
        sum=sum+score[i];
    ave=sum*1.0/N;
    printf("ave=%.2f\n",ave);
    for(i=0;i<N;i++)
        if(score[i]<ave)
            printf("%5d",score[i]);
    return 0;
}
