#include <stdio.h>
//-------------------------------------------------
int count(char tab[], char c)
{
    int i,counter=0;

    for(i=0;tab[i+1]!=0;i++)
    {
        if(tab[i]==c) counter++;
    }
    return counter;
}
//------------------------------------------------
int count_string(char tab[], char tab2[])
{
    int i,j,counter=0,spr=0,ile=0;

    for(i=0;tab2[i+1]!=0;i++)
    {
        counter++;
    }

    for(i=0;tab[i+1]!=0;i++)
    {
        if(tab[i]==tab2[0])
        {
            for(j=0;tab2[j+1]!=0;j++)
            {
                if(tab[i+j]==tab2[j])
                {
                    spr++;
                }
            }
        }
        if(counter==spr)
        {
            ile++;
        }
        spr=0;
    }
    return ile;
}
//--------------------------------------------------------------------------
int count_all_of(char tab[], char tab2[], int size2)
{
    int i,j,ile=0;

    for(i=0;tab[i+1]!=0;i++)
    {
        for(j=0;j<size2;j++)
        {
            if(tab[i]==tab2[j])
            {
                ile++;
            }
        }
    }
    return ile;
}
//-----------------------------------------------------------------
int main()
{
    char tekst[1000],tekst2[1000];
    int counter=0,i;

    printf("wpisz tekst:\n");
    fgets(tekst,1000,stdin);

    printf("wpisz drugi tekst:\n");
    fgets(tekst2,1000,stdin);

    for(i=0;tekst2[i+1]!=0;i++)
    {
        counter++;
    }

    printf("%d\n%d\n%d", count(tekst,tekst2[0]), count_string(tekst,tekst2), count_all_of(tekst,tekst2,counter));
    //printf("%d\n%d", findAny(tekst,tekst2,counter),findLastAny(tekst,tekst2,counter));

    return 0;
}
