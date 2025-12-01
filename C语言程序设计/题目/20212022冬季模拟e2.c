#include <stdio.h>
int main()
{
    float s;
    scanf("%f",&s);
    if(s>=85.0)
        printf("Excellent");
    else if (s>=70)
        printf("Good");
    else if(s>=60)
        printf("Not Bad");
    else
        printf("Try again");

    return 0;
}
