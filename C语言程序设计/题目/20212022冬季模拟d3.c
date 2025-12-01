#include <stdio.h>
int main()
{
    char s[6][6];
    int i,j,ji,he=0;
    for(i=0;i<6;i++)
        for(j=0;j<6;j++)
            scanf("%c",&s[i][j]);
    for(i=0;i<6;i++)
    {
      ji=0;
      for(j=0;j<6;j++)
        {
            if(s[i][j]=='A')
            {
                he=he*10+j+1;
                ji=ji+1;
            }
           if(j==5&&ji!=1)
                he=he*10;
        }
    }
        printf("%d",he);




    return 0;
}
