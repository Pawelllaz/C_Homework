#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	char c;
	float z,f,d;
	printf("przeliczanie kwoty w zlotowkahch na funty/dolary (wpisz 'f' lub 'd' ):");
	scanf("%c", &c); 
	printf("wpisz kwote w zltowkach:");
	scanf("%f", &z);
	switch (c)
	{
		case 'f':
		f = z / 4.73384861;
		printf("w przeliczeniu na funty: %.2f", f);
		break;
		
		case 'd':
		d = z / 3.61005617;
		printf("w przeliczeniu na dolary: %.1f", d);
		break;
	}
	printf("\n\tdane na dzien 25-10-2017");	
	
	return 0;
}
