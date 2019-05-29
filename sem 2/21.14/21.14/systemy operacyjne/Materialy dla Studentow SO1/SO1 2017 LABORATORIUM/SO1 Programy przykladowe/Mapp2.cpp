#include <windows.h>
#include <cstdlib>
#include<cstdio>
using namespace std;

int main()         // Mapp2
{
HANDLE hF=NULL;		// uchwyt do pliku
HANDLE hMapFile=NULL;	// uchwyt do obiektu reprezentujacego plik zmapowany
char *pMapFile;			// wskaznik na poczatek obszaru zmapowanego pliku
char str[3][7], nameF[30] = "E:\\dlaMapp2.txt";
char Buf[] = "abcdefghijklmnoprstuvwz"; 
DWORD writed = 0; 
int size = sizeof(str[0])-1, i, sizeBuf = sizeof(Buf)-1;        

hF = CreateFile(nameF, GENERIC_READ|GENERIC_WRITE,0,0, OPEN_ALWAYS, 0,0);
   if (hF == INVALID_HANDLE_VALUE) { 
      printf("CreateFile error: %d.\n", GetLastError()); getchar(); return(1);}

BOOL wynik = WriteFile(hF, Buf, sizeBuf, &writed, NULL); 
if (!wynik) {   printf("ReadFile error %d.\n", GetLastError() ) ; getchar(); return (3); }

DWORD sizeF=GetFileSize(hF, 0); printf("sizeFile = %d\n", sizeF);
hMapFile=CreateFileMapping (hF, NULL, PAGE_READWRITE, 0, sizeF+8,  NULL);
	if(hMapFile==NULL) { printf("CreateFileMapping error: %d\n", GetLastError()); 
                        getchar(); return 1; }

	// Przydzielenie obszaru PAO na odwzorowanie pliku
pMapFile = (char *)MapViewOfFile (hMapFile, FILE_MAP_ALL_ACCESS, 0,  0,  0);

puts(pMapFile);  

	// Odczyt danych z pliku (z PAO) i umieszczenie ich w tablicy
for (i=0; i<3; i++) { memcpy(str[i], pMapFile+i*size, size);  str[i][6]='\0'; }	
printf("\nZawartosc tablicy z fragmentami pliku \n"); for (i=0; i<3; i++) puts(str[i]);

	// zmiana danych w pliku poprzez bezposredni zapis do PAO
	//strncpy(str[1],"123456", 6);
	memcpy(pMapFile+1*size, "123456", size);

UnmapViewOfFile (pMapFile);
CloseHandle(hF); CloseHandle(hMapFile);
puts("----odczyt z pliku po modyfikacji:");
char zn;
FILE *pF1 = fopen(nameF, "r");
while ((zn=getc(pF1)) !=EOF) putc(zn, stdout); fclose(pF1);	

// getchar(); 
return 0;
}

