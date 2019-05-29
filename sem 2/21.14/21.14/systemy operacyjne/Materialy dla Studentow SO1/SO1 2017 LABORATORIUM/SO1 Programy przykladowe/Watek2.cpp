#include <iostream>
#include <windows.h>
#include <process.h>
#include <conio.h>
using namespace std;
VOID Znak(LPVOID);

int main() 			    // Watek2  - wiele w¹tków i jedna funkcja bazowa
{
char zn1 = '1',     zn2 = '2',     zn3 = '3';
   _beginthread(Znak, 0,   &zn1);
// for (int k=0; k<30000; k++) pow(sin(k), 3.3);
 //  _beginthread(Znak, 0,   &zn2);
 //  _beginthread(Znak, 0,   &zn3);
Sleep(2000);            // czekanie na koniec pracy w¹tków

for(int i = 0; i < 30; i++) {   		  // 30 liter A co 40 ms
    cout << "A" << ' ';
    cout.flush();    
	Sleep(40);
	}
cout << "\n Wcisnij Klawisz";      getch(); 
return 0;
}
VOID Znak(LPVOID lpzn)
{     // 30 znakow z parametru lpzn co 20 ms
char znak = *((char*) lpzn);
for(int i = 0; i < 30; i++)  {
    cout << znak << '  ';
    cout.flush();
    Sleep(20);
    }
}

