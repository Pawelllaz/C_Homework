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

    int c[N],b=0,wyraz[N];
    for(i=0;i<N;i++)
    {
        wyraz[i]=0;
        c[i]=0;
    }
    for(i=a;i>=0;i--)
    {
        if(tekst[i]>='a' && tekst[i]<='z')
        {
            c[b]+=1;
        }
        else if(tekst[i]>='A' && tekst[i]<='Z')
        {
            c[b]+=1;
        }
        else if(tekst[i]==' ')
        {
            wyraz[b]=i+2;
            b++;

        }
    }
    int maxi=c[0];
    for(i=0;i<=b;i++)
    {
        if(c[i]>maxi)
        {
            maxi=c[i];
        }
    }

    int r=0,ktory[N];
    for(i=0;i<=b;i++)
    {
        if(maxi==c[i])
        {
            ktory[r]=wyraz[i];
            r++;
        }
    }

    printf("%d %d\n", r,maxi);

    int x;
    for(i=0;i<r;i++)
    {
        if(ktory[i]==0)
        {
            for(x=0;x<maxi;x++)
            {
                printf("%c", tekst[x]);
            }
        }
        else
        {
            for(x=ktory[i]-1;x<ktory[i]+maxi;x++)
            {
                printf("%c", tekst[x]);
            }
        }
        printf("\n");
    }
	return 0;
}
