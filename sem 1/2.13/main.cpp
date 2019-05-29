#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int i;
	float liczby[5], mmax, mmin, avg;



	printf("wpisz 5 liczb:\n");
	for(i=0;i<5;i++)
	{
		scanf("%f", &liczby [i]);
	}

	mmax = liczby[0];
	mmin = liczby[0];

	for (i=1;i<5;i++)
	{
	    if (liczby[i] > mmax)
		{
			mmax = liczby[i];
		}
		else if (liczby[i] < mmin)
		{
			mmin = liczby[i];
		}
	}

	avg = (liczby [0]+liczby [1]+liczby [2]+liczby [3]+liczby [4])/ (5);

	printf("\n%.2f\n%.2f\n%.2f\n", mmin,mmax,avg);

return 0;
}
