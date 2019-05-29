#include <process.h>
#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

VOID Znak(LPVOID);

int main()   			 					// Watek1
{
char zn ='Z';
printf("adres_zn: %p \n", &zn);

_beginthread(Znak,	0, &zn);   				 // watek potomny

for(int i = 0; i < 30; i++) {			     // 30 liter A co 40 ms
	printf("A ");
	fflush(stdin);    
for (long k=0; k<50000; k++) pow(pow(pow(sin(k), 3.3), 2.2), 1.1);
//	Sleep(40);			// fatalny spowalniacz wyœwietlanych znaków
	}

printf("\n Koniec Main"); 
// getchar();
return 0;
}

VOID Znak(LPVOID parm)       // 30 znakow z parametru zn co 20 ms
{
printf("adres_parm: %p \n", parm);    
char znak = *((char*)parm);			// konwersja parametrów
for(int i = 0; i < 30; i++) {
    printf("%c ", znak );
    fflush(stdin);    
    Sleep(20);
	}
_endthread();    // mozna pominac
}

