#include <windows.h>
#include <cstdlib>
#include<cstdio>
using namespace std;
#define BYTEStoREAD  14
int main()   										// Mapp1
{
DWORD readed = 0, writed=0;
char buf[BYTEStoREAD],   buf1[BYTEStoREAD];  
char nameF[30] = "E:\\dlaMapp1.txt", *pb ;	
HANDLE  f, ff, fm;  
// ----------- Utworzenie ObiektuPliku w j¹drze 
   f = CreateFile(nameF, GENERIC_READ|GENERIC_WRITE,0,0, CREATE_ALWAYS, 0, 0);
      WriteFile(f, "qwert asdfgh", 12, &writed, NULL);   
 printf("rozmiar pliku: %d \n", GetFileSize(f, NULL));

//--------------Utworzenie obiektu reprezentujacego plik zmapowany
fm = CreateFileMapping(
    f,				 	     // wskaznik na ObiektPlikowy od  CreateFile
    NULL,					// standardowe atrybuty bezpieczenstwa
    PAGE_READWRITE,		    // czytanie i pisanie (powiazany z 2-gim param. CreateFile)
    0,					    // maly plik
    sizeof(buf),			// rozmiar pliku
    NULL );				    // bez wlasnej nazwy 
//-------Przydzielenie obszaru w PAO na odwzorowanie pliku 
pb = (char*)MapViewOfFile(
    fm,					       // uchwyt zwrócony przez  CreateFileMapping
    FILE_MAP_WRITE,			   // tylko do pisania
    0,					       // maly plik
    0,					       // mapowanie od poczatek pliku
    0  );					   // mapowania calego pliku
memcpy(pb + writed, "123456", 6);           // bezposredni zapis do PAO
UnmapViewOfFile((void *)pb);            // zwolnienie pamieci przeznaczonej na odwzorowanie pliku
CloseHandle(fm);   CloseHandle(f);       // zamkniecie uchwytow do Obiektów j¹dra

puts("Odczyt funkcjami systemu Windows po modyfikacji");     
ff = CreateFile(nameF, GENERIC_READ, 0,0, OPEN_EXISTING, 0,0);
 printf("rozmiar pliku: %d \n", GetFileSize(ff, NULL));
ReadFile(ff, buf1, BYTEStoREAD, &readed, NULL);
puts(buf1);          
  
CloseHandle(ff);

puts("-----Odczyt kontrolny funkcjami jezyka C++");
char zn;  
FILE *pF = fopen(nameF, "r");
while ((zn=getc(pF)) !=EOF) putc(zn, stdout); 
fclose(pF);
// getchar();   
return 0;
}
