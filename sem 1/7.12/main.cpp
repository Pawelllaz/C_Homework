#include <stdio.h>
#include <stdlib.h>

float row(float a,float b,float c,float x)
{
    return a*x*x+b*x+c;
}

int main()
{
    float a,b,c,x;
    printf("podaj a=");
    scanf("%f", &a);
    printf("podaj b=");
    scanf("%f", &b);
    printf("podaj c=");
    scanf("%f", &c);
    printf("podaj x=");
    scanf("%f", &x);

    printf("wynik=%f", row(a,b,c,x));
    return 0;
}
