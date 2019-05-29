#include <windows.h>				// wspoldzielenie przez DZIEDZICZENIE uchwytu
#include <cstdio> 
#include <cstdlib>          
using namespace std;

void BubbleSort(double *, int);
void Disp(double *, int, char *);

int main(int argc, char *argv[]) 		 // Map1aDziedziczenie  - macierzysty
{
HANDLE hFile=NULL;		// uchwyt do pliku
HANDLE hMapFile=NULL;		// uchwyt do obiektu reprezentujacego plik zmapowany
BYTE *pMapFile;		// wskaznik na poczatek obszaru zmapowanego pliku
int nData = 40000; 
double pocz = 3.3, kon = 99.8;
char cmd1[128], nameF[33] = "Map1a_Dziedz.bin";
DWORD sizeF = nData*sizeof(double);
double *A = new double[nData];  

hFile = CreateFile(nameF, GENERIC_READ|GENERIC_WRITE,0,0, CREATE_ALWAYS,0,0);
   if (hFile == INVALID_HANDLE_VALUE) { 
      printf("CreateFile error: %d.\n", GetLastError()); getchar(); return(1);}

SECURITY_ATTRIBUTES sa;
sa.nLength = sizeof(sa);  sa.lpSecurityDescriptor = NULL;
sa.bInheritHandle = TRUE;   // zmiana uchwytu na dziedziczny.

hMapFile=CreateFileMapping (hFile, &sa, PAGE_READWRITE, 0, sizeF,  NULL);
	if(hMapFile==NULL) { printf("CreateFileMapping error: %d\n", GetLastError()); 
                        getchar(); return 1; }

pMapFile = (BYTE *)MapViewOfFile (hMapFile, FILE_MAP_WRITE, 0,  0,  0);
if(pMapFile==NULL) { printf("in Map1aDz MapVievOfFile error: %d\n", GetLastError()); 
                        getchar(); return 1; }

STARTUPINFO si = {0};  si.cb = sizeof(STARTUPINFO);  PROCESS_INFORMATION  pi;
sprintf(cmd1, "Map1bDziedziczenie %d %g %g %p", nData, pocz, kon, hMapFile);
BOOL OK = CreateProcess(0,cmd1, 0,0, TRUE, 0,0,0, &si,&pi);
	   if(!OK) { printf("CreateProcess error: %d\n", GetLastError()); 
                        getchar(); return 1; }
Sleep(2000); 
// odczyt danych z pliku (z PAO) i przes³anie do tablicy A
memcpy(A, pMapFile, sizeF);
BubbleSort(A, nData); 		 // sortowanie tablicy A
memcpy(pMapFile, A, sizeF);  // zapis do pliku dyskowego (mapowanego)
delete [] A;
UnmapViewOfFile (pMapFile);
CloseHandle(hMapFile);  CloseHandle(hFile); 

puts("\n----odczyt kontrolny z pliku dyskowego w Map1aDziedziczenie:");
double *B = new double[nData]; 
FILE *pF1 = fopen(nameF, "rb");
fread(B, sizeof(double), nData, pF1); fclose(pF1);
Disp(B, 16, "" );
delete [] B;

puts("Koniec Map1aDziedziczenie");  
// getchar();
return 0;
}

void BubbleSort(double *X, int size)
{
double w;
for (int i = 1; i < size; i++)
  for (int j = size-1; j >= i; j--)
   if (X[j] < X[j - 1]) { w=X[j-1]; X[j-1]=X[j]; X[j]=w; };
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
