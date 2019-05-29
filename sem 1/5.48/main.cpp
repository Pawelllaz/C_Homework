#include <stdio.h>
#include <stdlib.h>
#define N 250
#define isovocal(x) x=='a' || x=='A' || x=='e' || x=='E' || x=='i' || x=='I' || x=='o' || x=='O' || x=='u' || x=='U' || x=='y' || x=='Y'
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	int i, a;
	char tekst[N],sam[N];
	printf("wpisz tekst:\n");
	fgets(tekst,N,stdin);
	a=0;
	for(i=0;tekst[i]!=0;i++)
	{
        a++;
	}

    int b=0,spr;
    for(i=0;i<a-1;i++)
    {
        if(tekst[i]=='a' || tekst[i]=='A' || tekst[i]=='e' || tekst[i]=='E' || tekst[i]=='i' || tekst[i]=='I' || tekst[i]=='O' || tekst[i]=='o' || tekst[i]=='U' || tekst[i]=='u' || tekst[i]=='Y' || tekst[i]=='y')
        {
            sam[b]=tekst[i];
            b++;
        }
    }
    int c,d=0;
    for(i=0;i<b;i++)
    {
        spr=0;
        for(c=i;c>=0;c--)
        {
            if(sam[i]==sam[c] && i!=c)
                spr++;
        }
        if(spr==0)
            d++;
    }
    printf("%d ", d);
return 0;
}
