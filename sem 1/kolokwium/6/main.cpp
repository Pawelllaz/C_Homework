#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>

int mirror(int tab[],int m,int n)
{
    int a,b,liczba;

    for(a=0;a<m;a++)
    {
        for(b=0;b<n;b++)
        {
            liczba=tab[a*b];
            tab[a*b]=tab[(m-a)*(n-b)];
            tab[(m-a)*(n-b)]=liczba;
            liczba=0;
        }
    }
    return tab[m*n];
}


int main()
{
    const int M=60;
    const int N=120;

    srand(time(0));
    int A[M*N],i,j;

    for(i=0;i<M*N;i++)
    {
        A[i]=rand()%101;
    }

    int wynik[M*N];

   wynik[M*N]=mirror(A,M,N);

    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%3d ", wynik[i*j]);
        }
        printf("\n");
    }

    return 0;
}
