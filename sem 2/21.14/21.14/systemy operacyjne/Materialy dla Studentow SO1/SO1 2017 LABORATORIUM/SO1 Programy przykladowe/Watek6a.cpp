#include <iostream>       
#include <windows.h>
#include <process.h>
#include <cmath>
using namespace std;

UINT WINAPI ZNAK(LPVOID);   

void WatekGlowny(int, char);

int main()        // Watek6a Oczekiwanie na zakoñczenie pracy w¹tku
{
HANDLE hWatek1 = NULL, hWatek2 = NULL;  
UINT IDWatek1 = 0, IDWatek2 = 0;
DWORD Wynik1, Wynik2;
char zn1='A', zn2='*';
hWatek1 = (HANDLE)_beginthreadex(NULL, 0, ZNAK, &zn1, 0, &IDWatek1);
hWatek2 = (HANDLE)_beginthreadex(NULL, 0, ZNAK, &zn2, 0, &IDWatek2);

		// WatekGlowny(200, '#');  

Wynik1=WaitForSingleObject(hWatek1, INFINITE); // czeka a¿ watek1 zakonczy dzialanie
	
for(int i = 0; i < 30; i++)	{ // wypisuje 30 liter A co 80 ms
		cout << "G ";
		cout.flush();
		Sleep(80);
	    } 

CloseHandle(hWatek1);  CloseHandle(hWatek1);       // zamykanie watkow
cout << "\nKoniec MAIN";  
return 0;
}

UINT WINAPI ZNAK(LPVOID zn)
{
  
for(int i = 0; i < 30; i++)	{  // wypisuje 30 razy znak z parametru co 20 ms 
		cout << *((char*)zn) << ' ';
		cout.flush();
		Sleep(80);
	    } cout << endl;
_endthreadex(0);
} 

void WatekGlowny(int n, char zn)              // d³ugotrwa³e obliczenia
{
for (int k1=0; k1 < n; k1++){   
      for (int k2=0; k2<20000; k2++) pow(sin(k1),3.3)* pow(cos(k1),2.2); 
      cout << zn <<" ";
      } cout << "\n";
}


