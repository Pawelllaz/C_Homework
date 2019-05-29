#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {

	int i, l[1000], sp,sn;
	sp =0;
	sn =0;
	printf("wpisz liczbe:\n");

	for(i=0;i<=1000;i++)
	{
		scanf("%d", &l[i]);
		if(l[i]==-1)
		{
			break;
		}
		else if(i==1000)
		{
			printf("blad wcytywania danych");
			break;
		}
		if(l[i] % 2 == 0)
		{
			sp+=l[i];
		}
		else
		{
			sn+=l[i];
		}
	}

	printf("suma parzystych: %d\nsuma nieparzytych: %d", sp,sn);

	return 0;
}
