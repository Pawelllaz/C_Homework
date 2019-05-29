#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Napisz program do sumowania n?10 losowych liczb rzeczywistych z zakresu [-5,5]. 
Wartoœæ n ma byæ podawana przez u¿ytkownika.
 Wydrukuj na konsoli po kolei wszystkie wylosowane liczby z dok³adnoœci¹ do 6 miejsc dziesiêtnych i wynik sumowania z dok³adnoœci¹ do 4 miejsc dziesiêtnych.
  Ka¿dy wydruk zakoñcz znakiem nowej linii. */

int main(void) {
	float a= -5, b= 5;
	srand(time(0));
	double los = (a + rand() *(b-a));
	
	printf("%g", los);
	
	
	return 0;
}
