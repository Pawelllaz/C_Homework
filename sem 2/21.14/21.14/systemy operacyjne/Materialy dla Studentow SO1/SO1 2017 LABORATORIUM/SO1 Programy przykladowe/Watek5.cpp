#include <iostream>
#include <windows.h>
#include <process.h>
#include <cmath>
using namespace std;

#define MAX_THREADS 3
UINT WINAPI ZNAK(LPVOID);
void WatekGlowny(int, int, char);

int main()                                  // Watek5
{
int i;
DWORD Th1, Th2, Th3;
unsigned ID0, ID1, ID2;
HANDLE hW[MAX_THREADS]; 
char zn1='1', zn2='2', zn3='3';   

hW[0] = (HANDLE)_beginthreadex( NULL,0, ZNAK, &zn1, CREATE_SUSPENDED, &ID0);
hW[1] = (HANDLE)_beginthreadex( NULL,0, ZNAK, &zn2, CREATE_SUSPENDED, &ID1);
hW[2] = (HANDLE)_beginthreadex( NULL,0, ZNAK, &zn3, CREATE_SUSPENDED, &ID2);

SetThreadPriority(hW[0], THREAD_PRIORITY_LOWEST);
SetThreadPriority(hW[1], THREAD_PRIORITY_TIME_CRITICAL);
SetThreadPriority(hW[2], THREAD_PRIORITY_LOWEST);

for(i=0; i < MAX_THREADS; i++ )	ResumeThread(hW[i]);
WatekGlowny(80, 50000, '*');
 
for(i=0; i < MAX_THREADS; i++) CloseHandle(hW[i]);
cout << "\n Wcisnij Klawisz"; 
// cin.get();
return 0;
}

UINT WINAPI ZNAK(LPVOID lpzn)  	// 30 znakow z parametru lpzn        
{
for(int i = 0; i < 60; i++)	{
        for (int k=0; k<95000; k++) cos(sin(pow(log(k+1),2.2)));           	
        cout << *((char*)lpzn) << ' ';
        cout.flush();
  }
}


void WatekGlowny(int n1, int n2, char zn)       // d³ugotrwa³e obliczenia
{
for (int k1=0; k1 < n1; k1++){   
      for (int k2=0; k2 < n2; k2++) pow(sin(k1),3.3)* pow(cos(k1),2.2); 
      cout << zn;
      }  cout << endl;
}

