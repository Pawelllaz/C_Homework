#include<stdio.h>
#include<stdlib.h>

int main() {

	int i,d,j,a[5][5],b[5][5],spr=0;

	printf("podaj liczby:\n");

	for(i=0; i<5; i++)
    {
		for(d=0; d<5; d++)
		{
			scanf("%d", &a[i][d]);
		}
		rewind(stdin);
	}

	for(i=0; i<5; i++)
    {
		for(d=0; d<5; d++)
        {
			scanf("%d",&b[i][d]);
		}
		rewind(stdin);
	}

	for(i=0;i<5;i++)
    {
        printf("%d ",i);
		for(d=0;d<5;d++)
		{
			for(j=0;j<5;j++)
			{
				if(a[i][j]==b[j][d])
                    spr++;
			}
			if(spr==5)
			{
				printf("%d ",d);
			}
			spr=0;
		}
		printf("\n");
	}

	return 0;
}
