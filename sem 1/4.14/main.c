#include <stdio.h>
#include <stdlib.h>
#define N 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	int i;
	float l[100], mmin,mmax,avg,s=0;

	printf("wpisz 100 liczb:\n");
	for(i=0;i<N;i++)
	{
		scanf("%f", &l[i]);
        s+=l[i];
	}
	mmin=l[0];
	mmax=l[0];
	for(i=0;i<N;i++)
	{
		if(mmax<=l[i])
		{
			mmax=l[i];
		}
		else if(mmin>l[i])

		{
			mmin=l[i];
		}
	}
	avg = s / 100;

	printf("min: %.2f\nmax: %.2f\nsrednia: %.2f", mmin,mmax,avg);


	return 0;
}
