#include <stdio.h>

int potega(int a, int b)
{
    int i;
    if(b==0) return 1;
    for(i=1;i<b;i++)
    {
        a*=a;
    }
    return a;
}
//---------------------------------------
void printf_with_comas(long long a)
{
    printf("%lli\n", a%10);
    int i, counter=1,j;
    for(i=0;;i++)
    {
        if(a/(potega(10,i))>0)
        {
            counter++;
        }
        else
        {
            break;
        }
    }

    int ile=counter/3;

    for(i=0;i<ile;i++)
    {
        for(j=1;j<=3;j++)
        {

        }
    }
}

int main()
{
    long long a;

    printf("podaj liczbe: ");
    scanf("%lli", &a);

    printf_with_comas(a);

    return 0;
}
