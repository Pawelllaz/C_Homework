#include <iostream>
#include <windows.h>
#include <process.h>
#include <cmath>
using namespace std;
const int MAX = 5;          // krotnosc wyswietlanych lancuchow
UINT WINAPI DispA(LPVOID);
UINT WINAPI DispB(LPVOID);
void OBLICZENIA(char, int);
HANDLE hMutex = NULL;

int main()       			         // Mutex1
{
char txtA[] = "AAAAAAAAAAAA", txtB[] = "BBBBBBBBBBBBBBBB";	
UINT     ID_A=0, ID_B=0;
hMutex = CreateMutex(NULL, FALSE, NULL);      // mutex sygnalizowany -> FALSE

HANDLE hWatekA = (HANDLE)_beginthreadex(NULL, 0, DispA, txtA, 0, &ID_A);
HANDLE hWatekB = (HANDLE)_beginthreadex(NULL, 0, DispB, txtB, 0, &ID_B);

OBLICZENIA('*', 600);
CloseHandle(hMutex);
cout << "\n Koniec MAIN";
return 0;              
} 

UINT WINAPI DispA(LPVOID tekst)
{
char t, *txt = (LPSTR)tekst;
for(int i=0; i < MAX; i++){		
 OBLICZENIA('1', 40);		            
  WaitForSingleObject(hMutex, INFINITE);                  // Czekaj(mutex)
     for(int i = 0; *(txt + i); i++) {
	  for (long k2=0; k2<90000; k2++) cos(sin(pow(log(k2+1),2.2))); 
	  cout << *(txt + i);
      }
  ReleaseMutex(hMutex);                          // Sygnalizuj(mutex), zwalnia
 OBLICZENIA('a', 40);  // -------Reszta Kodu  	
  } 
cout << "\n Koniec1 \n"; 
} 

UINT WINAPI DispB(LPVOID tekst)
{
LPSTR txt = (LPSTR)tekst;
for(int i=0; i < MAX; i++){		
  OBLICZENIA('2', 40);		            
  WaitForSingleObject(hMutex, INFINITE);
    for(int i = 0; *(txt + i); i++) {
	  for (long k2=0; k2<90000; k2++) cos(sin(pow(log(k2+1),2.2))); 
	  cout << *(txt + i); 
	}
  ReleaseMutex(hMutex);
  OBLICZENIA('b', 40);
} 
cout << "\n Koniec2 \n";  
_endthreadex(0); 
} 


void OBLICZENIA(char zn, int n)  
{
for (int k1=0; k1 < n; k1++){   
  for (long k2=0; k2<60000; k2++) cos(sin(pow(log(k2+1),2.2))); 
  cout << zn;
 } 
}



