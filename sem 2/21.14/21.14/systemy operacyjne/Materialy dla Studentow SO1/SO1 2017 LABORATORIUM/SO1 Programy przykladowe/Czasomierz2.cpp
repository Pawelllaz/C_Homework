#include <iostream>
#include <windows.h>
#include <process.h>
#include <cmath>
using namespace std;

UINT WINAPI Licz(LPVOID);
typedef struct PARM {
     char zn;
     int nn;
     } *pPARM;

HANDLE Czasomierz(WORD Min, WORD Godz, WORD Dz)
{
HANDLE		hTimer;
SYSTEMTIME	st;
FILETIME		ftLocal, ftUTC;
hTimer = CreateWaitableTimer(NULL, TRUE, NULL);   
st.wYear		= 2015;	// parametry pierwszego zasygnalizowania 
st.wMonth		= 7;	
st.wDayOfWeek	= 0;	
st.wDay		    = Dz;		
st.wHour		= Godz;	
st.wMinute		= Min;		
st.wSecond		= 0;
st.wMilliseconds= 0;		
SystemTimeToFileTime(&st, &ftLocal);  
LocalFileTimeToFileTime(&ftLocal, &ftUTC); 	     
                                  //dzia≥a poprawnie tylko na plaszczyünie x86
SetWaitableTimer(hTimer, (LARGE_INTEGER*)&ftUTC,   0,   NULL, NULL, FALSE);
cout << "Czekam na "<< st.wHour<<':'<<st.wMinute << "..."<< endl;
return hTimer;
}       

int main() 			 // Czasomierz2
{
HANDLE	hTimerA;
UINT ID0=0, ID1=0, ID2=0;   
HANDLE hWA = NULL, hWB = NULL; 
DWORD wynikWait = 0;    
PARM parmA={'A', 50}, parmB={'B', 50}, parmG={'*', 70}, parm0={'^', 70};;

_beginthreadex(NULL, 0, Licz, &parm0, 0, &ID0);

hTimerA = Czasomierz(47, 22, 18);

wynikWait = WaitForSingleObject(hTimerA, INFINITE);
if (wynikWait == WAIT_OBJECT_0) 
     hWA = (HANDLE)_beginthreadex(NULL, 0, Licz, &parmA, 0, &ID1);
 hWB = (HANDLE)_beginthreadex(NULL, 0, Licz, &parmB, 0, &ID2);

Licz(&parmG);

CloseHandle(hTimerA);  CloseHandle(hTimerA);
cout << endl<< "KONIEC."; 
// cin.get();   
return (0);
}  

UINT WINAPI Licz(LPVOID parametr)  
{
pPARM st = (pPARM)parametr;   
char zn= st->zn; int n= st->nn;
double w = 0;;
for (int k1=0; k1 < n; k1++){   
  for (long k2=0; k2 < 110000; k2++) w += cos(sin(pow(log(k2+1),2.2))); 
  cout << zn;
 } 
}

