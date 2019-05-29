#include <stdio.h>
#define N 100

int starts_with(char tab1[], char tab2[])
{
    int spr=0,i;

    for(i=0;tab2[i+1]!=0;i++)
    {
        if(tab1[i]==tab2[i])
        {
            //dobrze
        }
        else
        {
            spr++;
        }
    }
    if(spr==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int ends_with(char tab1[], char tab2[])
{
    int i,counter1=0,counter2=0,spr=0;
    for(i=0;tab1[i+1]!=0;i++)
    {
        counter1++;
    }

    for(i=0;tab2[i+1]!=0;i++)
    {
        counter2++;
    }

    for(i=counter1-1;i>=counter1-counter2;i--)
    {
        if(tab1[i]==tab2[counter2-counter1+i])
            {
                //dobrze
            }
        else
            {
                spr++;
            }
    }
     if(spr==0)
        {
            return 1;
        }
        else
            {
            return 0;
            }
}

int main()
{
    char tab1[N],tab2[N];
    rewind(stdin);
    printf("podaj tekst:\n");
    fgets(tab1,N,stdin);
    rewind(stdin);
    printf("podaj drugi tekst do porownania:\n");
    fgets(tab2,N,stdin);

    printf("start %d\nend %d", starts_with(tab1,tab2), ends_with(tab1,tab2));

    return 0;
}
