#include <stdio.h>
#define N 1000
int main()
{
   int n,i,a[N],count1=0,count2=0,t,min,max;
   printf("Input n:");
   scanf("%d",&n);
   printf("Input %d integers:",n);
   for(i=0;i<n;i++)
   {
      scanf("%d",&a[i]);
   }
   min=a[0];
   for(i=0;i<n;i++)
   {
      if(min>a[i])
         min=a[i];
   }
   for(i=0;i<n;i++)
   {
      if(a[i]==min)
         break;
      count1++;
   }
   t=a[0];
   a[0]=min;
   a[count1]=t;
   max=a[0];
   for(i=0;i<n;i++)
   {
      if(max<a[i])
         max=a[i];
   }
   for(i=0;i<n;i++)
   {
      if(a[i]==max)
         break;
      count2++;
   }
   t=a[n-1];
   a[n-1]=max;
   a[count2]=t;
   printf("After swapped:");
   for(i=0;i<n;i++)
   {
      printf("%4d",a[i]);
   }
   return 0;
}
