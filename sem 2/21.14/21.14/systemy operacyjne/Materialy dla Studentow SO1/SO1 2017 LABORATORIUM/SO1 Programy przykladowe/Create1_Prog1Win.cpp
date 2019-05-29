#include <windows.h>        // CreateP4a

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR pszCmdLine, int iCmdShow)
{
char linia[] = "D:\\Prog1Win.exe 625  5457  81";
BOOL ok;
STARTUPINFO si = {0};
si.cb = sizeof(STARTUPINFO);
PROCESS_INFORMATION pi;
ok = CreateProcess(0, linia, 0, 0, 0, 0, 0, 0, &si, &pi);
return 0;
}
