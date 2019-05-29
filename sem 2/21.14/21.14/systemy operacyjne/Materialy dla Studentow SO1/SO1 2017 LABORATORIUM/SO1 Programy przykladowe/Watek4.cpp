#include <iostream>
#include <windows.h>
#include <process.h>
#include <conio.h>
using namespace std;
VOID ZNAK(LPVOID lpVoid);

int main()                              // Watek4
{
CHAR zn = 0, znA = 'A', znB = 'B';
HANDLE hWatekA = NULL;
HANDLE hWatekB = NULL;
BOOL CzyWatekAZawieszony = FALSE;
BOOL CzyWatekBZawieszony = FALSE;
	// uruchamienie 2-ch watkow i zapamietanie uchwytu
hWatekA = (HANDLE)_beginthread(ZNAK, 0, &znA);
hWatekB = (HANDLE)_beginthread(ZNAK, 0, &znB);
for(;;)	{
   if(kbhit() != 0) { // pobieranie znaku z klawisza
   zn = getch();
   if(zn == 'A' || zn == 'a')      // zawieszanie lub wznawianie 1-go watku
      if(CzyWatekAZawieszony == FALSE) {
			SuspendThread(hWatekA);
			CzyWatekAZawieszony = TRUE;
			} else
				{ ResumeThread(hWatekA);
				  CzyWatekAZawieszony = FALSE;
				}
   if(zn == 'B' || zn == 'b')    // zawieszanie lub wznawianie 2-go watku
       if(CzyWatekBZawieszony == FALSE) {
			SuspendThread(hWatekB);
			CzyWatekBZawieszony = TRUE;
				} else
				{ ResumeThread(hWatekB);
				  CzyWatekBZawieszony = FALSE;
				}
// spacja przerywa petle for i konczy funkcje main,
// koniec pracy watkow potomnych, wypisujacych A i B
   if(zn == ' ') break;
      } 
   } 
return 0;
} 
VOID ZNAK(LPVOID lpzn)
{
for(;;)	{         // znak w lpzn co 20 ms 
   cout << *((char*)lpzn) << ' ';
   cout.flush();
   Sleep(20);
   }
_endthread();
}
