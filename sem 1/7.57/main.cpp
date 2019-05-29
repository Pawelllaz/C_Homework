#include <stdio.h>
#define N 100

int is_palindrom(int tab[], int size, int start_index, int end_index)
{
    int i,spr=0;

    if(size==0) return 0;
    for(i=0;i<size/2;i++)
    {
        printf("tab[%d]=(%d) == tab[%d]=(%d)\n", start_index+i, tab[start_index+i], end_index-i, tab[end_index-i]);
        if(tab[start_index+i]==tab[end_index-i])
        {
            //dobrze
        }
        else
        {
            spr++;
        }
    }
    if(spr==0)
    {
        printf("tutututututututututututututuututututut\n");
        return 1;
    }

    return 0;
}
//-----------------------------------------------------------------------
int main()
{
    int tab[N], start, koniec,counter=0,i,j;

    printf("podaj liczby: ");
    for(i=0;i<N;i++)
    {
        scanf("%d", &tab[i]);
        if(tab[i]==-1)
        {
            break;
        }
        counter++;
    }

    int ilosc=0, dlugosc=0,palindromy[100][2];
    for(i=0;i<counter;i++)
    {
        for(j=counter-1;j>0;j--)
        {
            if(is_palindrom(tab,i-j,i,j))
            {
                palindromy[ilosc][0]=i;
                palindromy[ilosc][1]=i-j;
                ilosc++;
            }
        }
    }

    int maxi=palindromy[0][1],indeksy[100];

    for(i=0;i<ilosc;i++)
    {
        if(palindromy[i][1]>maxi)
        {
            maxi=palindromy[i][1];
        }
    }

    int ile_maxi=0;
    counter=0;
    for(i=0;i<ilosc;i++)
    {
        if(maxi==palindromy[i][1])
        {
            ile_maxi++;
            indeksy[counter++]=palindromy[i][0];
        }
    }

    printf("%d\n%d\n", maxi, ile_maxi);
    for(i=0;i<counter;i++)
    {
        printf("%d ", indeksy[i]);
    }

    return 0;
}
