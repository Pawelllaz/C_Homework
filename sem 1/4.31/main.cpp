#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Napisz program do sumowania n?10 losowych liczb rzeczywistych z zakresu [-5,5]. 
Warto�� n ma by� podawana przez u�ytkownika.
 Wydrukuj na konsoli po kolei wszystkie wylosowane liczby z dok�adno�ci� do 6 miejsc dziesi�tnych i wynik sumowania z dok�adno�ci� do 4 miejsc dziesi�tnych.
  Ka�dy wydruk zako�cz znakiem nowej linii. */

int main(void) {
	float a= -5, b= 5;
	srand(time(0));
	double los = (a + rand() *(b-a));
	
	printf("%g", los);
	
	
	return 0;
}
