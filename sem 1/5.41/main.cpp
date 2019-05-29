#include <stdio.h>
#include <stdlib.h>
#define n 100
//-------------------------------------------------
int clamp(int v,int lo, int hi)
{
    if(v>=lo && v<=hi)
        return v;
    if(v>=hi && v<=lo)
        return v;
    if(v>hi && hi>lo)
        return hi;
    if(v>hi && lo>hi)
        return lo;
    if(v<lo && lo<hi)
        return lo;
    if(v<lo && hi<lo)
        return hi;
    if(hi==lo)
        return hi;
    return 0;
}
//-------------------------------------------------
int main()
{
    int tab1[n],tab2[n],i,counter1,counter2,c;
    counter1=0;
    counter2=0;

    printf("wpisz dwa ciagi liczb:\n");

    for(i=0;i<n;i++)
    {
        c=scanf("%d", &tab1[i]);
        if(c!=1 || tab1[0]==-1)
        {
            printf("bledne dane wejsciowe!!");
            return 0;
        }
        if(tab1[i]==-1)
            break;
        counter1++;
    }

    for(i=0;i<n;i++)
    {
        c=scanf("%d", &tab2[i]);
        if(c!=1 || tab2[0]==-1)
        {
            printf("bledne dane wejsciowe!!");
            return 0;
        }
        if(tab2[i]==-1)
            break;
        counter2++;
    }


    int wkaz;
    for(i=0;i<counter1;i++)
    {
        wkaz=clamp(tab1[i],0,counter2-1);
        printf("%d ", tab2[wkaz]);
    }

    return 0;
}
