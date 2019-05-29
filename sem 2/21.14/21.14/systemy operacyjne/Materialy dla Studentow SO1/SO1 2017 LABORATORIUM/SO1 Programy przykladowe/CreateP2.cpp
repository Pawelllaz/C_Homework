#include <windows.h>						
#include<cstdio>
using namespace std;

int main()						// CreateP2
{
char nazwaOkna[ ] = "Windows Explorer";
char komunikat[ ] = "Czy chcesz przegl¹daæ katalogi";
char program[ ] = "c:\\Windows\\explorer";     // musi byæ explorer.exe gdy jest 1-szym parametrem
char bufor[128];
int ok = MessageBoxEx(NULL, komunikat, nazwaOkna, MB_YESNO | MB_ICONQUESTION, 0 ); 
if (ok == IDYES) {
STARTUPINFO si = {0};
si.cb = sizeof(STARTUPINFO);
PROCESS_INFORMATION pi;
 BOOL ok1 = CreateProcess(program, 0, 0, 0, 0, 0, 0, 0, &si, &pi);
      if (!ok1)  {
            wsprintf(bufor, "Uruchomienie Explorer'a  '%s' nie powiod³o sie!\0", program);
            MessageBoxEx( NULL, bufor, nazwaOkna, MB_OK|MB_ICONINFORMATION , 0 ); 
            }
      HANDLE  uchwytProcesu = pi.hProcess;
      printf("uchwytProcesu = %p", uchwytProcesu);
      }

//getchar(); 
return 0; 
}
