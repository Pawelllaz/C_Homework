#include <windows.h>
#include <cstdlib>
#include<cstdio>
using namespace std;

#define BYTEStoREAD  150
DWORD INVALID_SET_FILE = 0xFFFFFFFF;

int main()                                      // Plik1
{
DWORD OFFSET = 7, readed = 0;
HANDLE hFile;							// Uchwyt do pliku
char Wy[BYTEStoREAD];	 				// bufor Wy
char nameFile[33] = "E:\\Plik1.txt" ;

hFile = CreateFile(         // ------------utworzenie pliku do odczytu
     nameFile,                  // Nazwa pliku
     GENERIC_READ,			    // Tylko czytanie z pliku
     FILE_SHARE_READ,			// Wspoldzielenie czytania z pliku
     NULL,				  	    // Standardowe parametry bezpieczeñstwa						
     OPEN_EXISTING,			    // Plik musi istnieæ
     FILE_ATTRIBUTE_NORMAL,	    // Nie ma specyficznych atrybutów 
     NULL );                    // Nie korzystamy z obiektu template					
   if (hFile == INVALID_HANDLE_VALUE) {
            printf("CreateFile error %d.\n", GetLastError()) ;
            getchar(); return (1); }

DWORD dwPtr = SetFilePointer( // ------ustawienie miejsca odczytu w pliku
       hFile,		              // Uchwyt do pliku wczesniej utworzonego
       OFFSET, 			          // Liczba bajtów do przesuniecia
       NULL, 				      // U¿ywany przy du¿ych plikach
       FILE_BEGIN) ; 		      // Ustawienie na pocz¹tek pliku
   if (dwPtr == INVALID_SET_FILE) { 
              printf("SetFilePointer error %d.\n", GetLastError()) ;
              getchar(); return (2); }

BOOL bResult = ReadFile(      // -----------------------odczyt z pliku
            hFile,	            // Uchwyt pliku 
			Wy, 				// Tablica Wyjsciowa
			BYTEStoREAD, 		// Liczba bajtów do wczytania
			&readed, 			// pointer na liczbe wczytanych bajtów  
			NULL) ; 			// Operacja synchroniczna		
   if (!bResult) { printf("ReadFile error %d.\n", GetLastError()) ;
                   getchar(); return (3); }
												
if(readed == BYTEStoREAD) printf("Pelny Odczyt zakonczony pomyslnie\n");
   else printf("?? Wczytano %d ze %d bajtow zalozonych\n", readed, BYTEStoREAD);
puts(Wy);
CloseHandle(hFile);
// getchar();
return 0;
}

