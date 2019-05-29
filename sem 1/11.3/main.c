#include <stdio.h>
#include <stdlib.h>
#define N 1000
int main()
{

    char tab[N];
    int i,counter=0;

    for(i=0;i<N;i++)\
    {
        tab[i]='q';
    }

    fgets(tab,N,stdin);

    for(i=0;i<N;i++)
    {
        if(tab[i]>='0' && tab[i]<='9')
        {
            counter++;
        }
        if(tab[i]==47 || tab[i]==45 || tab[i]==43 || tab[i]==42)
        {
            counter++;
        }
    }

    int a,b;
    for(i=0;i<counter;i++)
    {
        if(tab[i]>='0' && tab[i]<='9' && tab[i+1]>='0' && tab[i+1]<='9')
        {
            a=tab[i]*10+tab[i+1];
            i++;
        }
        else if(tab[i]>='0' && tab[i]<='9')
        {
            a=tab[i];
            i++;
        }

        if(tab[i+1]>='0' && tab[i+1]<='9' && tab[i+2]>='0' && tab[i+2]<='9')            // druga liczba
        {
            b=tab[i]*10+tab[i+1];
        }
        else if(tab[i+1]>='0' && tab[i+1]<='9')
        {
            b=tab[i];
        }

        switch tab[i]
        {
        case '+':

        }

    }



    return 0;
}
