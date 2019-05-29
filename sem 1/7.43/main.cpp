#include <stdio.h>
//=========================================
int find(char tab[], char tab2[],int start)
{
    int i,j,counter=2,spr=0;

    for(i=start;tab[i+1]!=0;i++)
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
            return i+1;
        }
        spr=0;
    }
    return -1;
}
//======================================
int count(char tab[], char c)
{
    int i,il=0;

    for(i=0;tab[i+1]!=0;i++)
    {
        if(tab[i]==c)
        {
            tab[il]=i;
            il++;
        }
    }
    return il;
}
//======================================
int main()
{
    char tekst[1000];
    int counter=0,indeksy[1000],i;

    printf("wpisz tekst:\n");
    fgets(tekst,1000,stdin);

    for(i=0;tekst[i+1]!=0;i++)
    {
        counter++;
    }

    int ile=count(tekst,'.');

    int dlugosci[ile],il=0,spr=0;

    for(i=0;i<ile-1;i++)
    {
       /* if(tekst[i]!=0 && i==0)
        {
            dlugosci[il]=tekst[i];
            indeksy[il]=tekst[i];
            il++;
            dlugosci[il]=tekst[i+1]-tekst[i]-1;
            indeksy[il]=tekst[i];
        }*/
        /*if(i==ile-1 && i!=counter)
        {
            dlugosci[il]=counter-1-tekst[i];
            indeksy[il]=tekst[i];
           // printf("%d-%d=%d    i%d\n", counter-1,tekst[i],dlugosci[il],i);
        }
        else
        {*/
            dlugosci[il]=tekst[i+1]-tekst[i]-1;
            indeksy[il]=tekst[i];
            //printf("%d-%d=%d    i%d\n", tekst[i+1],tekst[i],dlugosci[il],i);
        il++;
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
