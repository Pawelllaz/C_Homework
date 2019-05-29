#include<iomanip>
#include<iostream>
#include <cstdlib>
#include<cmath>
#include<ctime>
using namespace std;
void BubbleSort(double *, int);

void DispV(int, int, double *,char *);

double Generuj(float a, float b) 
   { double w = (a + (b - a)*(double)rand()/RAND_MAX);  return floor(w*100+0.5)/100; } 
const int MaxObieg = 5; 

int main(int argc, char *argv[ ]) 						 // Test_BubbleSort
{
clock_t T1, T2; 
double Time, oda, dob;
int  nData; 
if (argc <= 1 ) { nData = 12000; oda = 2.2; dob = 88.8; }
  else { nData= atoi(argv[1]); oda = atof(argv[2]); dob = atof(argv[3]); } 
double *A = new double[nData];						// dynamiczna tablica
for (int k = 0; k < MaxObieg; k++) {
for (int i = 0; i < nData; i++) A[i] = Generuj(oda, dob);	//generowanie danych
if (k==0) { cout << "Fragment Danych ( z " << nData << "):"; DispV(0, 32, A , ""); }
T1 = clock();   
BubbleSort(A, nData);  					// sortowanie 
T2 = clock();
Time = (T2 - T1)/(double)CLOCKS_PER_SEC;
 cout << "Obieg Nr "<< k << "  czas = " << Time << endl;
     }
DispV(0, 32, A, "Fragment po Sortowaniu:" );
delete [ ] A;
cout << "Koniec Test_BubbleSort";  cin.get();
return 0;
}


void BubbleSort(double *X, int size)
{
double w;
for (int i = 1; i < size; i++)
  for (int j = size-1; j >= i; j--)
   if (X[j] < X[j - 1]) { w=X[j-1]; X[j-1]=X[j]; X[j]=w; };
}

void DispV(int a, int b, double V[ ], char *text )
{
  cout << text;  
  for(int i=a; i < b; i++) {
     if (i%6 == 0) cout << endl;     
     cout << setw(7) << V[i];
     }   cout << endl;
}

