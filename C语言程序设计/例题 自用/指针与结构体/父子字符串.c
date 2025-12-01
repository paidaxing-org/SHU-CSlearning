#include <stdio.h>

#include<string.h>

int main()

{

	char a[90],b[90];

	int i,j,isfind=0,amount=0;

        printf("please input two strings\n");

	gets(a);

	gets(b);

	for(i=0;i<strlen(a);i++)

	{

		if(a[i]==b[0])

		{

			isfind=1;

			for(j=0;j<strlen(b);j++)

			{

				if(a[i+j]!=b[j])

                               {

					isfind=0;

					break;

				}

			}

		}

		if(isfind){

			amount++;

			isfind=0;

		}

	}

	printf("%d",amount);

	return 0;

}

