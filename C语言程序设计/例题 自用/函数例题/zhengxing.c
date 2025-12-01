#include <stdio.h>
#define N 50
void mix(int a[],int b[],int c[]);
int main()
{
  int A[5],B[5];
  int C[5];
  int i,j;
  printf("Please Enter Array A,5 digits:");
  for(i=0;i<5;i++)
  {
    scanf("%d",&A[i]);
  }
  printf("Please Enter Array B,5 digits:");
  for(i=0;i<5;i++)
  {
    scanf("%d",&B[i]);
  }
  printf("A B intersection is:");
  mix(A,B,C);
  return 0;
}
void mix(int a[],int b[],int c[])
{
  int i,j;
  int s=0;
  for(i=0;i<5;i++)
  {
    for(j=0;j<5;j++)
    {
      if(a[i]==b[j])
      {
        c[s]=a[i];
        s=s+1;
        break;
      }
    }
  }
  for(i=0;i<s;i++)
  {
    printf("%4d",c[i]);
  }
}
