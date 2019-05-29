#include <windows.h> 		 // CreateP1 - 1-szy i 2-gi parametr
int WINAPI WinMain (HINSTANCE hInstance,   HINSTANCE hPrevInstance,
                                    LPSTR lpCmdLine,  int iCmdShow)
{ 
BOOL ok1, ok2;
  char program[ ] = "c:\\Windows\\notepad.exe";
  char linia1[ ] = "  E:\\tekst1.txt";
  char linia2[ ] = "notepad   E:\\tekst2.txt";
STARTUPINFO si = {0};
si.cb = sizeof(STARTUPINFO);
PROCESS_INFORMATION  pi;
   ok1 = CreateProcess(program, linia1, 0, 0, 0, 0, 0, 0,  &si, &pi);
   ok2 = CreateProcess(      0,      linia2, 0, 0, 0, 0, 0, 0,  &si, &pi);
     HANDLE  uchwytProcesu2 = pi. hProcess;
return 0; 
}
