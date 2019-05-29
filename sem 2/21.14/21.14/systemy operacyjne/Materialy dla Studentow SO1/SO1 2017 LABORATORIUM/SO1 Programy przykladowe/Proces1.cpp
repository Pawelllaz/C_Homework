#include <iostream>
#include <windows.h>
using namespace std;

int main(int argc, char* argv[ ]) 			// Proces1
{
char cmd1[ ] = "Prog1 ";
char cmd2[ ] = "Prog1    24  225  81";
char cmd3[ ] = "explorer";
   
    STARTUPINFO si = {0};
    si.cb = sizeof(STARTUPINFO);
    PROCESS_INFORMATION  pi;

CreateProcess(0, cmd1, 0,0,0,0,0,0,  &si, &pi);
CreateProcess(0, cmd2, 0,0,0,0,0,0,  &si, &pi);
CreateProcess(0, cmd3, 0,0,0,0,0,0,  &si, &pi);

// wypisuje parametry programu Proces1
	cout << "Parametry wywolania programu:" << endl;
	for(int i = 0; i < argc; i++)
		cout << "argv[" << i << "] -> " << argv[i] << endl;

cout << "Koniec MAIN \n"; 
// cin.get();
return 0;
}

