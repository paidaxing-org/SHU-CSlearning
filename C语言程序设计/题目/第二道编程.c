#include <stdio.h>
int main()
{
    int a[10][10]= {{0},{0}};
    int b[5]= {0};
    int c[5]= {0};
    int i,j,n,s1,s2,s=0,k;
    scanf("%d%d",&s1,&s2);
    for(i=0; i<s1; i++)
        for(j=0; j<s2; j++)
            scanf("%d",&a[i][j]);
    for(k=0; k<=4; k++)
        for(j=0; j<s2; j++)
        {
            if(2*k+1<=s2)
                b[k]=b[k]+a[2*k][j];
            else
                break;
        }
    for(i=0; i<5; i++)
    {
        if(b[i]!=0)
            s=s+1;
    }

    for(i=0; i<s; i++)
    {
        printf("%d:",b[i]);
        while (b[i]!=0)
        {
            c[i]=c[i]*10+b[i]%10;
            b[i]=b[i]/10;
        }
        while(c[i]!=0)
        {
            n=c[i]%10;
            switch(n)
            {
            case 0:
                printf("ling ");
                break;
            case 1:
                printf("yi ");
                break;
            case 2:
                printf("er ");
                break;
            case 3:
                printf("san ");
                break;
            case 4:
                printf("si ");
                break;
            case 5:
                printf("wu ");
                break;
            case 6:
                printf("liu ");
                break;
            case 7:
                printf("qi ");
                break;
            case 8:
                printf("ba ");
                break;
            case 9:
                printf("jiu ");
                break;
            case 10:
                printf("shi ");
                break;
            }
            c[i]=c[i]/10;
        }
        printf("\n");
    }
    return 0;
}
