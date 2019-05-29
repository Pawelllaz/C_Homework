#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

int main()              // TickCount2
{
DWORD OldTime, ActualTime=0, Time = 0;
OldTime = GetTickCount();
for (long k=0; k < 99000; k++) log(pow((pow(sin(k),3.3)),2.2));
ActualTime = GetTickCount();
Time = ActualTime - OldTime;
cout << Time<< endl;
cout << "\nWcisnij Enter"; cin.get();
return 0;
}
