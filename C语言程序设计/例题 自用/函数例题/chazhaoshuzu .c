#include <stdio.h>
int a[81];
int search(int a[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (a[i] == x) break;
    if (i == n)return -1;
    else return i;
}
int main()
{
    int x,n,i=0;
    printf("Input n:");
    scanf("%d",&n);
    printf("Input %d integers:",n);
    for(i=0; i<=n-1; i++)
        scanf("%d",&a[i]);
    printf("Input x:");
    scanf("%d",&x);
    if(search(a,n,x)==-1)
        printf("Not Found\n");
    else
        printf("index=%d\n",search(a,n,x));
    return 0;
}

