#include <stdio.h>
#include <stdlib.h>
#define N 1000

int main()
{
    int ciag[N],i,counter,c,maax,miin;
    counter=0;

    printf("wpisz liczbe:\n");

    for(i=0;i<N;i++)
    {
        c=scanf("%d", &ciag[i]);
        if(c!=1 || ciag[0]==0)
        {
            printf("blad wprowadzania danych");
            return 0;
        }
        if(ciag[i]==0 && i!=0)
        {
            break;
        }
        counter++;
    }

    maax=ciag[0];
    miin=ciag[0];
    int ma=0,mi=0,avg;
    for(i=0;i<counter;i++)
    {
        if(maax>ciag[i])
        {
            maax=ciag[i];
            ma=i;
        }
        if(miin<ciag[i])
        {
            miin=ciag[i];
            mi=i;
        }
    }

    avg=(mi+ma)/2;

    printf("%d", ciag[avg]);



    return 0;
}
