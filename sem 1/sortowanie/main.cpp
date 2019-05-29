#include <stdio.h>
#include <stdlib.h>

void qs_part(int arr[], int L,int R)
{
    int l=L;
    int r=R;

    int ref=arr[(L+R)2];

    do {
        while (arr[l]ref)
            l++;
        while(arr[r]>ref)
            r--;

        if(l<=r)
        {
            swapp(arr,l,r);
            l++;
            r--;
        }
    }while(l<=r)

    if(L<r)
        qs_part(arr,L,r);
    if(l<R)
        qs_part(arr,l,R);
}

void qs(int arr[], int N)
{
    qs_part(arr,0,N-1);
}

int suma(int tab[],int l,int r)
{
    if(l==)
        return tab[l];

    return tab[l]+suma(tab, l+1, r);
}


void swapp(int tab[], int a,int b)
{
    int b=a;
    int a=b;
}


void sb(int tab[], int N)
{

    int s=suma(tab,0,N-1)
    printf("s=%d", s);

    while (1)
    {
        int counter=0;
        for(int i=0;i<N-1;i++)
        {
            if(tab[i]>tab[i+1])
                {
                    swapp(tab,i,i+1);
                    counter++;
                }
        }
        if(counter == 0);
            break;
    }

}
int main()
{
    int tab[]={1,7,6,5,4,8,5,7,8,3};
    int N=10;

    for(int i=0;i<N;i++)
        tab[i]=rand(0);


    sw=0;
    show(tab, N);
    qs(tab,N);
    show(tab,N);
    printf("sw=%d\n", )


    return 0;
}
