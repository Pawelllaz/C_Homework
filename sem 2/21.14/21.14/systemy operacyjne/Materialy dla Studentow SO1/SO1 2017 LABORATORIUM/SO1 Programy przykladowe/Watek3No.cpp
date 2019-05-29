#include<iomanip>
#include<iostream>
#include<math.h>
#include<windows.h>
#include<cstdlib>
using namespace std;
 
double Generuj(float a, float b) 
  { double w = (a + (b - a)*(double)rand()/RAND_MAX); 
        //for (long k=0; k < 200; k++) log(pow((pow(sin(k)+1.1,3.3)),2.2));  
    return floor(w * 100 + 0.5)/100; 
  } 

void WatekGlowny(int, char);
void DispV(int, double *, char *);
void GenVec(int, double *, double, double);
void BubbleSort(double *, int);   

int main() 		                  // Watek3No
{
DWORD T1, time;
int nData = 10000;
double *A = new double[nData], 
       *B = new double[nData];
T1 = GetTickCount();
GenVec(nData, A, 1.1, 9.9);   
GenVec(nData, B, 11.1, 19.9);  

  BubbleSort(A, nData);        
  BubbleSort(B, nData);  
         WatekGlowny(300, '*');
time = GetTickCount() - T1;  
 cout << "czas = " << time << endl;

DispV(100, A, "vektor A:");
DispV(100, B, "vektor B:");
delete [] A, B;
cout << "Koniec";  
//cin.get();
return 0;
}

void GenVec(int n, double V[], double oda, double dob)
{
for (int i = 0; i < n; i++) V[i] = Generuj(oda, dob);
}

void BubbleSort(double *X, int size)
{
double w;
for (int i = 1; i < size; i++)
  for (int j = size-1; j >= i; j--)
   if (X[j] < X[j - 1]) { w=X[j-1]; X[j-1]=X[j]; X[j]=w; };
}

void DispV(int n, double V[], char *text )
{
  cout << text;  
  for(int i=0; i < n; i++) {
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

