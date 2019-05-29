#include <stdio.h>
#define N 100
#include <time.h>
#include <cstdlib>
void shuffle(int tab[], int size)
{
    int i,los[size],il=0,j,tab2[size];
    srand(time(0));

    for(i=0;i<size;i++)
    {
        los[il]=rand()%size;
        for(j=il-1;j>=0;j--)
        {
            if(los[il]==los[j])
            {
                il--;
                i--;
                break;
            }
        }
        il++;
    }

    for(i=0;i<size;i++)
    {
        tab2[i]=tab[i];
    }

    for(i=0;i<size;i++)
    {
        tab[los[i]]=tab2[i];
    }
}

int main()
{
    int tab[N],i,counter=0;

    printf("wpisz pierwszy wektor: ");
    for(i=0;i<N;i++)
    {
        scanf("%d", &tab[i]);
        if(tab[i]==0) break;
        counter++;
    }

    shuffle(tab, counter);

    for(i=0;i<counter;i++)
    {
        printf("%d ", tab[i]);
    }

    return 0;
}
