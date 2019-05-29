#include <windows.h>        // Prog1Win
#include <cstdlib>
#include <iostream>  
#include <math.h>
using namespace std;
     
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR pszCmdLine, int iCmdShow) 
{
double x; 
 int i;
cout << "Linia polecenia: " << pszCmdLine << endl;

cout << "-----Program Prog1Win----------\n";
cout << "argc= " << __argc << endl;
for (i=0; i < __argc; i++) cout << __argv[i] << endl;

if (__argc <= 1 ) cout << "brak parametrow ???\n";
 else
  for (i=1; i < __argc; i++) {
     x = atof(__argv[i]);
     cout <<  "sqrt(" << x << ") = " << sqrt(x) << endl;
     }

cout << "Koniec Prog1Win"; 
// cin.get();
return 0;
}

