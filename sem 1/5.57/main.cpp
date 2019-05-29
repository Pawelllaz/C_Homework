#include <stdio.h>
#include <stdlib.h>
#define N 1000

int main()
{
    int i,a,b=0;
	char tekst[N];

	a=0;
	printf("wpisz tekst:\n");
	fgets(tekst, N,stdin);
    for(i=0;tekst[i+1]!=0;i++)
    {
        if(tekst[i]>=65 && tekst[i]<=90)
        {
            a++;
        }
        else if(tekst[i]>=97 && tekst[i]<=122)
        {
            a++;
        }
        else if(tekst[i]==' ')
        {
            a++;
        }
    }

    for(i=0;i<=a;i++)
    {
        if(tekst[i]==' ')
        {
            b++;
        }
    }

    printf("%d", b+1);
    return 0;
}
