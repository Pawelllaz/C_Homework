#include <stdio.h>

int findAny(char tab[], char tab2[], int size2)
{
    int i,j;

    for(i=0;tab[i+1]!=0;i++)
    {
        for(j=0;j<size2;j++)
        {
            if(tab[i]==tab2[j])
            {
                return i;
            }
        }
    }
    return -1;
}

int findLastAny(char tab[], char tab2[], int size2)
{
    int i,counter=0,j;

    for(i=0;tab[i+1]!=0;i++)
    {
        counter++;
    }

    for(i=counter;i>=0;i--)
    {
        for(j=0;j<size2;j++)
        {
            if(tab[i]==tab2[j])
            {
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    char tekst[1000],tekst2[1000];
    int counter=0,i;

    printf("wpisz tekst:\n");
    fgets(tekst,1000,stdin);

    printf("wpisz drugi tekst:\n");
    fgets(tekst2,1000,stdin);

    for(i=0;tekst2[i+1]!=0;i++)
    {
        counter++;
    }

    printf("%d\n%d", findAny(tekst,tekst2,counter),findLastAny(tekst,tekst2,counter));

    return 0;
}
