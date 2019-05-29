#include <iostream>
#include <Windows.h>
using namespace std;
int main()              // TickCount1
{
DWORD OldTime = GetTickCount();
DWORD ActualTime = 0;
int n = 0;
while(n < 9) {
   ActualTime = GetTickCount();
   if((ActualTime - OldTime) >= 50) {
        n++;
        cout << "Obieg" << n << ":  " 
               << ActualTime << endl;
        OldTime = ActualTime;   }
  } 
cout << "\nWcisnij Enter"; cin.get();
return 0;
}
