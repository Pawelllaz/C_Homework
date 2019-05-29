#include <stdio.h>
#define N 17
//===================================================================
unsigned long long my_atol_ex_rec(char tab[], int start_index)
{
	if(!start_index) return tab[0]-'0';
	return tab[start_index] - '0' + 10*my_atol_ex_rec(tab, start_index-1);
}
//====================================================================
int main()
{
    int i,counter=0;
	char liczba[N];

	printf("Wpisz tekst\n");
	fgets(liczba,N,stdin);
	for(i=0;liczba[i+1]!=0;i++)
    {
        counter++;
    }

    for(i=0;i<counter;i++)
    {
        if(liczba[i]<'0' || liczba[i]>'9')
        {
            printf("Error");
            return 1;
        }
    }
    //printf("!%d %d ", !counter, counter);
	printf("%llu", my_atol_ex_rec(liczba,counter-1));
	return 0;
}
