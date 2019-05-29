#include<iomanip>
#include<iostream>
#include<cmath>
#include<windows.h>
#include<process.h>
#include<cstdlib>
using namespace std;
 
double Generuj(float a, float b) 
 { double w = (a + (b - a)*(double)rand()/RAND_MAX); 
      for (long k=0; k < 200; k++) log(pow((pow(sin(k)+1.1,3.3)),2.2)); 
   return floor(w * 100 + 0.5)/100; } 

void WatekGlowny(int, char);
void DispV(int, double *, char *);
UINT WINAPI GenVec(LPVOID);
UINT WINAPI BubbleSort(LPVOID);   
int const maxData = 30000 ;
double A[maxData], B[maxData];
struct PARM {
       int nData;
       double a, b, *X;
       char zn;
       };

int main() 		 // Watek3a
{
HANDLE hWatekG1=NULL, hWatekG2=NULL, hWatekS1=NULL, hWatekS2=NULL;
UINT ID_G1=0, ID_G2=0, ID_S1=0, ID_S2=0;
int nData = 30000;
PARM  parmGA = {nData, 1.1, 9.9, A, 'A'}, 
            parmGB = {nData, 10.1, 19.9, B, 'B'};
PARM  parmSA = {nData, 0, 0, A, 'C'}, 
             parmSB = {nData, 0, 0, B, 'D'};
DWORD T1 = GetTickCount();
hWatekG1 = (HANDLE)_beginthreadex(NULL, 0, GenVec, &parmGA, 0, &ID_G1);
hWatekG2 = (HANDLE)_beginthreadex(NULL, 0, GenVec, &parmGB, 0, &ID_G2);   
 
hWatekS1 = (HANDLE)_beginthreadex(NULL, 0, BubbleSort, &parmSA, 0, &ID_S1);
hWatekS2 = (HANDLE)_beginthreadex(NULL, 0, BubbleSort, &parmSB, 0, &ID_S2);

   WatekGlowny(300, '*'); 
cout << "czas = " << GetTickCount() - T1 << endl;
DispV(50, A, "vektor A:");
DispV(50, B, "vektor B:");
cout << "Koniec Programu"; 
// cin.get();
return 0;
}

UINT WINAPI GenVec(LPVOID  parametr)
{
PARM *parm = (PARM*)parametr;
int n = parm->nData; 
double oda = parm->a, dob = parm->b, *X = parm->X;
for (int i = 0; i < n; i++){
	   if (i%100 == 0) cout << parm->zn; 
     X[i] = Generuj(oda, dob);
     }
}

UINT WINAPI BubbleSort(LPVOID  parametr)
{ 
DWORD T1 = GetTickCount();
PARM *parm = (PARM*)parametr;
int size = parm->nData;  
double *X = parm->X, w;
for (int i = 1; i < size; i++){
   if (i%100 == 0) cout << parm->zn; 
  for (int j = size-1; j >= i; j--)
      if (X[j] < X[j - 1]) { w=X[j-1]; X[j-1]=X[j]; X[j]=w; };
      }
cout << "\nczasSort" << parm->zn <<'='<< GetTickCount() - T1 << "mS\n";
}


void DispV(int ile, double V[], char *text )
{
  cout << text;  
  for(int i=0; i < ile; i++) {
     if (i%8 == 0) cout << endl;     
     cout << setw(9) << V[i];
     }
     cout << endl;
} 

void WatekGlowny(int n, char zn)              // d³ugotrwa³e obliczenia
{
for (int k1=0; k1 < n; k1++){   
      for (int k2=0; k2<20000; k2++) pow(sin(k1),3.3)* pow(cos(k1),2.2); 
      cout << zn <<" ";
      } cout << "\n";
}


