#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

void Disp(double *, int, char *);
double Generuj(float a, float b) 
 { double w = (a + (b - a)*(double)rand()/RAND_MAX); 
   // for (long k=0; k < 1000; k++) log(pow((pow(sin(k)+1.1, 3.3)), 2.2)); // spowalniacz
   return floor(w*100+0.5)/100; 
  } 

int main(int argc, char *argv[]) 		 // Map1bDziedziczenie - potomny
{
HANDLE hMapFile;
int nData;
double oda, dob;
if (argc <= 1 ) { puts("Brak Danych"); return 10; }
 else { nData= atoi(argv[1]); oda = atof(argv[2]); dob = atof(argv[3]); 
        sscanf(argv[4], "%p", &hMapFile);} // pobranie wartoœci uchwytu od rodzica 

puts(".......poczatek procesu Map1bDziedziczenie........");
double *A = new double[nData];
DWORD sizeF = nData*sizeof(double);
for (int i = 0; i < nData; i++) A[i] = Generuj(oda, dob);
  Disp(A, 16, "  Fragment danych w Map1bDz:" );

BYTE *pMapFile = (BYTE *)MapViewOfFile(hMapFile, FILE_MAP_WRITE, 0,0, 0);
if(pMapFile==NULL) { printf("in Map1bDz MapVievOfFile error: %d\n", GetLastError()); 
                        getchar(); return 1; }

	puts("  -->zapis Danych do pliku mapowanego");
	memcpy(pMapFile, A, sizeF);

UnmapViewOfFile(pMapFile);
CloseHandle(hMapFile);
puts(".......koniec procesu Map1bDziedziczenie........");


delete [] A;
getchar();
return 0;
}



void Disp(double *X, int size, char *text)
{
int i;
puts(text);
for (i = 0; i < size; i++) { 
  printf("%6.2f ", X[i]);
  if ((i+1)%10 == 0) puts(""); 
 }
 if ((i+1)%10 != 0) puts("");
}

