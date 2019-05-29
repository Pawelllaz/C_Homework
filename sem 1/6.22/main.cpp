#include<stdio.h>
#include<stdlib.h>
int main() {
	float C[5];
	int i,d,A[5][5],liczba=0,mini=0,maxi=0,absolutemax=0;
	printf("podaj liczby:\n");
	for(i=0; i<5; i++)
	{
		for(d=0; d<5; d++)
        {
			scanf("%d",&liczba);
			A[i][d]=liczba;
		}
		rewind(stdin);
	}

	for(i=0; i<5; i++)
	{
		for(d=0; d<5; d++)
        {
			if(d==0)maxi=mini=A[d][i];
			else
            {
				if(maxi<A[d][i]) maxi=A[d][i];
				if(mini>A[d][i]) mini=A[d][i];
			}
		}
		C[i]=maxi-mini;
		if(i==0)
            absolutemax=C[i];
		else if(absolutemax<C[i])
            absolutemax=C[i];
	}
	for(i=0;i<5;i++) if(C[i]==absolutemax){
		for(d=0; d<5; d++) {
		printf("%d ", A[d][i]);
	}
	printf("\n");
	}


	return 0;
}
