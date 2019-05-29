#include <stdio.h>

int find(char tab[], char tab2[])
{
    int i,j,counter=0,spr=0;

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
            return i;
        }
        spr=0;
    }
    return -1;
}

int findLast(char tab[], char tab2[])
{
    int i,counter=0,counter2=0,j,spr;

    for(i=0;tab2[i+1]!=0;i++)
    {
        counter2++;
    }

    for(i=0;tab[i+1]!=0;i++)
    {
        counter++;
    }

    for(i=counter;i>=0;i--)
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
        if(counter2==spr)
        {
            return i;
        }
        spr=0;
    }
    return -1;
}

int main()
{
    char tekst[1000],tekst2[1000];

    printf("wpisz tekst:\n");
    fgets(tekst,1000,stdin);

    printf("wpisz drugi tekst:\n");
    fgets(tekst2,1000,stdin);

    printf("%d\n%d", find(tekst,tekst2),findLast(tekst,tekst2));

    return 0;
}
