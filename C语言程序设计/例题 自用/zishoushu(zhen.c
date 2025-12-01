#include <stdio.h>
#include <math.h>
int main()
{   int i,n,ji,s,j;
    for(i=1;i<=2;i++)
    {  ji=i*i;
       s=ji;
       j=-1;
       while(s!=0)
       {
           s=s/10;
           j=j+1;
       }
      ji=ji-pow(10,j);
      printf("%d",ji);
      if(ji=i)
        printf("%d",i);
    }


    return 0;
}
