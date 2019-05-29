#include <windows.h>
#include <iostream>
using namespace std;

int main()            		 			 // Czas
{  
char buf[256];
   GetTimeFormat(NULL, 0, NULL, NULL, buf, 255);
cout<<buf<<endl;

   GetDateFormat(NULL, NULL, NULL, NULL, buf, 255);
cout<<buf<<endl;

cout << "\nKONIEC"; 
// cin.get();

return 0; 
}
