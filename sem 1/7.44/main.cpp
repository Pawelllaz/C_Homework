#include <stdio.h>
#include <stdlib.h>
//======================================
int count(char tab[], char tab2[])
{
    int i,j,il=0,counter=0;

    for(i=0;tab2[i+1];i++)
    {
        counter++;
    }

    for(i=0;tab[i+1]!=0;i++)
    {
        for(j=0;j<=counter;j++)
        {
            if(tab[i]==tab2[j])
            {
                //printf("%c\n", tab[i]);
                tab[il]=i;
                il++;
                break;
            }
        }
    }
    return il;
}
//======================================
int main()
{
    char tekst[1000],tekst2[]="AaEeIiOoUuYy";
    int counter=0,indeksy[1000],i;

    printf("wpisz tekst:\n");
    fgets(tekst,1000,stdin);

    for(i=0;tekst[i+1]!=0;i++)
    {
        counter++;
    }

    int ile=count(tekst,tekst2);

    int dlugosci[ile],il=0,spr=0;

    for(i=0;i<ile-1;i++)
    {
        dlugosci[il]=tekst[i+1]-tekst[i]-1;
        indeksy[il]=tekst[i];
        il++;
        //printf("", tekst[i+1],tekst[i],dlugosci[il],i);
    }

    for(i=0;i<il;i++)
    {
        if(dlugosci[i]>0)
        {
            spr++;
        }
    }
    if(spr==0)
    {
        printf("Error");
        return 0;
    }
    int maxi=dlugosci[0];
    for(i=0;i<il;i++)
    {
        if(dlugosci[i]>maxi)
        {
            maxi=dlugosci[i];
        }
    }
    printf("%d\n", maxi);
    for(i=0;i<il;i++)
    {
        if(dlugosci[i]==maxi)
        {
            printf("%d ", indeksy[i]+1);
        }
    }

    return 0;
}
