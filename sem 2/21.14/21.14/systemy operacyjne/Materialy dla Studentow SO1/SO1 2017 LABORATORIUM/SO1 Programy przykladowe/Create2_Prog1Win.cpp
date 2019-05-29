#include <windows.h>      					// Create2_Prog1Win
#include <stdio.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                                 LPSTR lpCmdLine, int iCmdShow)
{
char nazwa[] = "D:\\Prog1Win.exe";
BOOL ok;
STARTUPINFO si = {0};
si.cb = sizeof(STARTUPINFO);
PROCESS_INFORMATION pi;

ok = CreateProcess(nazwa, lpCmdLine, 0, 0, 0, 0, 0, 0, &si, &pi);
if (!ok) puts("Zle.");
return 0;
}  

