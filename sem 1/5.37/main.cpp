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
    int ma=0,avg,counter2=0;
    for(i=0;i<counter;i++)
    {
        if(maax>ciag[i])
        {
            maax=ciag[i];
        }
        if(miin<ciag[i])
        {
            miin=ciag[i];
        }
    }

    for(i=0;i<counter;i++)
    {
        if(maax==ciag[i])
        {
            ma+=i;
            counter2++;
        }
        if(miin==ciag[i])
        {
            ma+=i;
            counter2++;
        }
    }
    avg=(ma)/counter2;

    printf("%d", ciag[avg]);



    return 0;
}
