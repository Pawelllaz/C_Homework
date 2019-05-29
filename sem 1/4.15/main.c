#include <stdio.h>
#include <stdlib.h>
#define N 1000

int main()
{
    int i,counter=0,c;

    float l[N],min,max,avg,s=0;

    printf("wpisz 100 liczb:\n");
    for(i=0;i<N;i++)
    {
        c=scanf("%f", &l[i]);
        if(c!=1)
        {
            printf("blad wprowadzenia danych");
            return 1;
        }
        if(l[i]==-1)
        {
            break;
        }
        counter++;
        s+=l[i];
    }

    max=l[0];
    min=l[0];
    for(i=0;i<counter;i++)
    {
        if(l[i]>max)
        {
            max=l[i];
        }
        if(l[i]<min)
        {
            min=l[i];
        }
    }

    avg=s/counter;

    if(counter!=0)
        printf("%.2f\n%.2f\n%.2f", min,max,avg);
    if(counter==0)
    {
        printf("blad danych");
        return 1;
    }
    return 0;
}
