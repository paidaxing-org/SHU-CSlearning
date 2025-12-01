#include <stdio.h>
#include <math.h>
int main()
{
	int i,a,b;
	for ( i = 1; i < 100000; i++)
	 {
		a = sqrt(i + 100);
		b = sqrt(i + 268);
		if (a* a == i + 100 && b * b == i + 268)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}
