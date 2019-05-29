#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate(int lotto[], int N, int start, int end)
{
    srand(time(0));

    int i,liczba,j,spr;

    for(i=0;i<N;i++)
    {
        spr=0;
        liczba=rand()%(end-start)+start;
        for(j=i-1;j>=0;j--)
        {
            if(lotto[j]==liczba)
            spr++;
        }
        if(spr==0)
        {
            lotto[i]=liczba;
            printf("%d ", lotto[i]);
        }
        else
        {
            i--;
        }
    }
}

int main()
{
    int N=6,beg=1,en=49,tab[1000];

    generate(tab,N,beg,en);

    return 0;
}
