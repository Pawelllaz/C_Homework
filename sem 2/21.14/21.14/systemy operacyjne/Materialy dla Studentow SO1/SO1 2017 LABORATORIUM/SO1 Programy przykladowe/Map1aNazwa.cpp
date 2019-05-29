#include<windows.h>
#include<cstdio>         
#include<cstdlib> 
using namespace std;

int main(void)         // Map1aNazwa  -  wspoldzielenie przez nazwe   
{
HANDLE hFile = NULL, hMapFile = NULL;	
char nameF[30] = "nowy.txt";  
DWORD sizeF = 30;  
					// wy³¹cznie roboczy zapis danych We dla Map1aNazwa 
					FILE *pF = fopen(nameF, "w"); fputs("abcdefghijklmnoprstuvwz", pF); fclose(pF);

hFile = CreateFile(nameF, GENERIC_READ|GENERIC_WRITE,0,0, OPEN_ALWAYS,0,0);
   if (hFile == INVALID_HANDLE_VALUE) { 
      printf("CreateFile error: %d.\n", GetLastError()); getchar(); return(1);}

hMapFile=CreateFileMapping (hFile, NULL, PAGE_READWRITE, 0, sizeF,  "Alfa1");
	if(hMapFile==NULL) { printf("CreateFileMapping error: %d\n", GetLastError()); 
                         getchar(); return 1; }
	// Przydzielenie obszaru PAO na odwzorowanie pliku
char *pMapFile = (char *)MapViewOfFile (hMapFile, FILE_MAP_ALL_ACCESS, 0,  0,  0);

printf("\nOdczytane Dane ze zmapowanego pliku:\n"); puts(pMapFile);

STARTUPINFO si = {0};  si.cb = sizeof(STARTUPINFO);  PROCESS_INFORMATION  pi;
CreateProcess(0,  "Map1bNazwa  Open ",  0,0,0,0,0,0,  &si, &pi);
Sleep(1000);

UnmapViewOfFile (pMapFile);
CloseHandle(hFile); CloseHandle(hMapFile);
puts("----kontrolny odczyt z pliku dyskowego przez Map1aNazwa:");
char zn;  FILE *pF1 = fopen(nameF, "r");
while ((zn=getc(pF1)) !=EOF) putc(zn, stdout); fclose(pF1);	

//getchar(); 
return 0;
}

