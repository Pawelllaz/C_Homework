#include <stdio.h>
#include <stdlib.h>
#define N 250
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int i,a;
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
    printf("%d", a);


	return 0;
}
