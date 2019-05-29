#include<windows.h>
#include<cstdio>         
#include<cstdlib> 
#include<cstring>
using namespace std;

int main(int argc, char *argv[ ])          // Map1bNazwa
{	
DWORD sizeF = 30;
HANDLE hMapFile,  hFile = (HANDLE)0xFFFFFFFF;  
      

if (strcmp(argv[1],"Open") == 0) { puts( ".......proces Map1bNazwa z Open .....");
   hMapFile=OpenFileMapping(FILE_MAP_WRITE,  FALSE,  "Alfa1"); }

else if (strcmp(argv[1],"Create") == 0) {puts(".......proces Map1bNazwa z Create ....."); 
   hMapFile=CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, sizeF,  "Alfa1"); }

if(hMapFile==NULL) { printf("***FileMapping error: %d\n", GetLastError());  getchar(); return 1; }

char *pMapFile = (char *)MapViewOfFile (hMapFile, FILE_MAP_ALL_ACCESS, 0,  0,  0);

	puts("  ***modyfikacja pliku bezposrednio w PAO");	
	memcpy(pMapFile+1*6, "12%456", 6);

UnmapViewOfFile (pMapFile);
CloseHandle(hMapFile);
puts(".......koniec procesu Map1bNazwa........");
return 0;
}

