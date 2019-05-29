// Critical Section synchronizuje dostêp do wspolnej tablicy
#include <iostream>  
#include<iomanip>       
#include <windows.h>
#include <process.h>
#include <cmath>
using namespace std;
 
UINT WINAPI GEN(LPVOID);
void Disp(int, double *, char *);

double Generuj(float a, float b) 
 { double w = (a + (b - a)*(double)rand()/RAND_MAX);  
        for (long k=0; k < 1200; k++) log(pow((pow(sin(k)+1.1, 3.3)), 2.2)); // spowalniacz_1
   return floor(w*100+0.5)/100; } 

void ObLiCzeNia(char, int);

const int MAXDATA = 2000;
double B[4000], A[MAXDATA];        // wspólna zmienna dzielona to tablica A
    typedef struct PARM { 
float aa, bb; 
char zn; } *pPARM;

CRITICAL_SECTION cs;

int main()                                      // Critical1
{
PARM parmA = {-9.0, -1.1, 'A'}, parmB = {11.11, 99.9, 'B'};  
UINT  ID1=0, ID2=0;
InitializeCriticalSection(&cs);
HANDLE hWA = (HANDLE)_beginthreadex(NULL, 0, GEN,  &parmA, 0, &ID1);
HANDLE hWB = (HANDLE)_beginthreadex(NULL, 0, GEN,  &parmB, 0, &ID2);
ObLiCzeNia('*', 200);
cout << "\nKoniec programu Critical1";  
return 0;              
} 

UINT WINAPI GEN(LPVOID parametr) 
{
pPARM st = (pPARM)parametr;
float oda = st->aa,  dob = st->bb; 
char zn=st->zn;
ObLiCzeNia(zn, 80);
EnterCriticalSection( &cs );  
  cout  << "\n W sekcji krytycznej_" << zn << endl;
     for (int i = 0; i < MAXDATA; i++) {
          A[i] = pow(Generuj(oda, dob), 1.0);
          }
     Disp(44, A, " ");
LeaveCriticalSection( &cs );  
int k;
double w=0;
ZeroMemory(B, 4000*sizeof(double));
for (k=0; k < 4000 ; k++) B[k] = log(pow((pow(sin(k)+1.1,3.3)),2.2));
for (k=0; k < 4000 ; k++) w += B[k];
cout << "\nKoniec Watka" << zn << ". w="<<w; 
}

void ObLiCzeNia(char zn, int n)  
{
double w;
for (int k1=0; k1 < n; k1++){   
  for (long k2=0; k2<80000; k2++) w = cos(sin(pow(log(k2+1),2.2))); 
  cout << zn;
 } 
}

void Disp(int size, double *X, char *text)
{
int i;
cout << text << endl;
for (i = 0; i < size; i++) { 
  cout <<  setw(7) << X[i] << "  ";
  if ((i+1)%6 == 0) cout << endl; 
 }
 if ((i+1)%6 != 0) cout << endl;
}










