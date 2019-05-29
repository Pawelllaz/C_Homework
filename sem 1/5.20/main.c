#include <stdio.h>
#include <stdlib.h>
#define N 1000
int main()
{
    int t[N],i,il[11],counter=0;

    for(i=0;i<=10;i++)
    {
        il[i]=0;
    }

    printf("wpisz liczby:\n");
    for(i=0;i<N;i++)
    {
        scanf("%d", &t[i]);
        if(t[i]==-1)
        {
            break;
        }
        counter++;
    }

    for(i=0;i<counter;i++)
    {
        if(t[i]>=0 && t[i]<=10)
        {
            switch (t[i])
            {
            case 0:
                il[0]++;
                break;
            case 1:
                il[1]++;
                break;
            case 2:
                il[2]++;
                break;
            case 3:
                il[3]++;
                break;
            case 4:
                il[4]++;
                break;
            case 5:
                il[5]++;
                break;
            case 6:
                il[6]++;
                break;
            case 7:
                il[7]++;
                break;
            case 8:
                il[8]++;
                break;
            case 9:
                il[9]++;
                break;
            case 10:
                il[10]++;
                break;
            }
        }
    }

    for(i=0;i<=10;i++)
    {
        printf("%d - %d\n", i,il[i]);
    }

    return 0;
}
