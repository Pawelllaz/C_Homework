#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Wylosuj 100 liczb ca�kowitych z zakresu < -1000,1000 >.
Policz ile z nich ma warto�� bezwzgl�dn� mniejsz� b�d� r�wn� 100 i wynik oblicze� wypisz na konsoli.
Wydruk w konsoli musi by� zako�czony znakiem nowej linii
*/
int main(void) {

	int i,sum;
	sum =0;
	srand (time(0));
	for(i=0;i<100;i++)
	{
		int a=rand()%2001 -1000;
		if(a>=-100 && a<=100)
		{
			sum ++;
		}
	}
	printf("%d\n", sum);


	return 0;
}
