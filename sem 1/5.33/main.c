#include <stdio.h>
#define N 100

int main() {

    int tab1[N],tab2[N],i,r,counter1,counter2,c,spr,a;

    printf("wpisz liczbe:\n");
    spr=0;
    counter1=0;
    counter2=0;
    for(i=0;i<N;i++)
    {
        c=scanf("%d", &tab1[i]);
        if(tab1[i]==0)
        {
            break;
        }
        else if(c!=1 || tab1[0]==0)
        {
            spr=1;
            break;
            printf("0");
        }
        counter1++;
    }
    for(i=0;i<N;i++)
    {
        if(spr==1)
            break;
        c=scanf("%d", &tab2[i]);

        if(tab2[i]==0 || c!=1)
        {
            break;
        }
        counter2++;
    }


    r=0;

    int b=0,cn[N];
    for(i=0;i<counter1;i++)
    {
        for(a=0;a<counter2;a++)
        {
            if(tab1[i]==tab2[a])
            {
                cn[b]=tab1[i];
                b++;
                r++;
                break;
            }
        }
    }
    for(i=0;i<b;i++)
    {
        spr=0;
        for(a=i;a>=0;a--)
        {
            if(cn[i]==cn[a] && i!=a)
            {
                spr++;
            }
        }
        if(spr==0)
            printf("%d ", cn[i]);
    }
    if(r==0)
    {
        printf("0");
    }
    return 0;
}
