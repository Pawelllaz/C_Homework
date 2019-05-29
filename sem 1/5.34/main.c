#include <stdio.h>
#define N 100

int main() {

    int tab1[N],tab2[N],i,c,counter1,counter2,spr;

    counter1=0;
    counter2=0;
    spr=0;

    printf("wpisz liczbe, aby zakonczyc ciag wpisz 0:\n");
    for(i=0;i<N;i++)
    {
        c=scanf("%d", &tab1[i]);
        if(c!=1 || tab1[0]==0)
        {
            printf("bledne dane wejsciowe");
            spr++;
            return 0;
        }
        else if(tab1[i]==0)
        {
            break;
        }
        counter1++;
    }

    for(i=0;i<N;i++)
    {
        if(spr!=0)
        {
            break;
        }
        c=scanf("%d", &tab2[i]);
        if(c!=1 || tab2[0]==0)
        {
            printf("bledne dane wejsciowe");
            spr++;
            return 0;
        }
        else if(tab2[i]==0)
        {
            break;
        }
        counter2++;
    }

    int tab[N],s,r,a;

    s=0;

    for(i=0;i<counter2;i++)
    {
        r=0;

        for(a=0;a<counter1;a++)
        {
            if(tab2[i]==tab1[a])
                r++;
        }
        if(r==0)
        {
            tab[s]=tab2[i];
            s++;
        }
    }

    int b,q=0,wyn[N];

    for(i=0;i<s;i++)
    {
        r=0;

        for(a=0;a<s;a++)
        {
            if(tab[i]==tab[a] && i!=a)
                r++;
        }
        if(r>=1)
        {
             wyn[q]=tab[i];
             q++;
        }
    }

    int f,o=0;

    for(i=0;i<q;i++)
    {
        f=0;
        for(b=i;b>=0;b--)
        {
            if(wyn[i]==wyn[b] && b!=i)
                f++;
        }
        if(f==0)
        {
            printf("%d ", wyn[i]);
            o++;
        }
    }

   if(o==0)
        printf("0");

    return 0;
}
