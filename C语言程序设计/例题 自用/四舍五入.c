#include <stdio.h>
int main()
{
    float a,b;
    char ch;
    printf("Please type your expression: ");
    scanf("%f%c%f",&a,&ch,&b);
    switch(ch)
    {
    case '+':
        printf("%f+%f=%f\n",a,b,a+b);
        break;
    case '-':
        printf("%f-%f=%f\n",a,b,a-b);
        break;
    case '*':
        printf("%f*%f=%f\n",a,b,a*b);
        break;
    case '/':
        if (b==0)
            printf("division by zero!\n");
        else
            printf("%f/%f=%f \n",a,b,a/b);

        break;
    default:
        printf("unknown operator.\n");
    }
    return 0;
}
