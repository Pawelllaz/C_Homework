#include <stdio.h>
#include <stdlib.h>
#define n 100

int main()
{
    int tab1[n],tab2[n],i,counter1,counter2,c;
    counter1=0;
    counter2=0;

    printf("wpisz dwa ciagi liczb:\n");

    for(i=0;i<n;i++)
    {
        c=scanf("%d", &tab1[i]);
        if(c!=1 || tab1[0]==0)
        {
            printf("bledne dane wejsciowe!!");
            return 0;
        }
        if(tab1[i]==0)
            break;
        counter1++;
    }

    for(i=0;i<n;i++)
    {
        c=scanf("%d", &tab2[i]);
        if(c!=1 || tab2[0]==0)
        {
            printf("bledne dane wejsciowe!!");
            return 0;
        }
        if(tab2[i]==0)
            break;
        counter2++;
    }

    int a,counter;

    for(i=0;i<counter1;i++)
    {
        counter=0;
        for(a=0;a<counter2;a++)
        {
            if(tab1[i]<tab2[a])
            {
                counter++;
            }
        }
        printf("%d ", counter);
    }

    return 0;
}
