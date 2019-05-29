#include <stdio.h>
#include <stdlib.h>
#define N 1000

int main()
{
    int i,counter=0;
    float liczby[N],mmin,mmax,avg,s=0;

    printf("wpisz liczby:\n");
    for(i=0;i<N;i++)
    {
        scanf("%f", &liczby[i]);
        if(liczby[i]==-1)
        {
            break;
        }
        counter++;
    }

    mmin=liczby[0];
    mmax=liczby[0];
    for(i=0;i<counter;i++)
    {
        if(liczby[i]<mmin)
        {
            mmin=liczby[i];
        }
        if(liczby[i]>mmax)
        {
            mmax=liczby[i];
        }
        s+=liczby[i];
    }

    avg=s/counter;

    printf("%.2f\n%.2f\n%.2f", mmin,mmax,avg);

    return 0;
}
