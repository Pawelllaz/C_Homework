#include <stdio.h>
#include <stdlib.h>
#define N 100

int is_palindrom_rec(int tab[], int start_index, int end_index)
{
    if(end_index<=start_index)
        return 1;
    else
    {
        int res=0;
        if(tab[start_index]==tab[end_index])
            res=is_palindrom_rec(tab,start_index+1,end_index-1);
        return res;
    }

}

int main()
{
    int tab[N],i,counter=0;

    printf("wprowadz liczby:\n");
    for(i=0;i<N;i++)
    {
        scanf("%d", &tab[i]);
        if(tab[i]==-1)
        {
            break;
        }
        counter++;
    }

    int w=is_palindrom_rec(tab,0,counter-1);
    if(w==1)
        printf("TAK");
    else
        printf("NIE");

    return 0;
}
