#include <stdio.h>
#include <stdlib.h>

int main() {

	char a[8];
	int i,x;
	x=0;

    printf("wpisz litere lub cyfre:\n");

	for(i=0;i<5;i++)
    {
		scanf("%c", &a[i]);
		rewind(stdin);
		if(a[i]=='x')
		{
			x += 1;
		}
		else if (a[i]=='y')
		{
			x+=1;
		}
		else if(a[i]=='z')
		{
			x+=1;
		}
		else if(a[i]=='2')
		{
			x+=1;
		}
		else if(a[i]=='7')
		{
			x+=1;
		}
	} // for

	printf("%d", x);




	/*	char a[4];
	int i,x,y,z,l2,l7;
	x=y=z=l2=l7=0;
	for (i=0;i<5;i++)
	{
		printf("Podaj literke lub cyferke %d\n",i+1);
		scanf("\n%c",&a[i]);
		rewind(stdin);
		if (a[i]==88 || a[i]==120) x++;
		if (a[i]==89 || a[i]==121) y++;
		if (a[i]==90 || a[i]==122) z++;
		if (a[i]==50) l2++;
		if (a[i]==55) l7++;
	}
	printf("x - %d, y - %d, z - %d, 2 - %d, 7 - %d",x,y,z,l2,l7);
	return 0; */


	return 0;
}
