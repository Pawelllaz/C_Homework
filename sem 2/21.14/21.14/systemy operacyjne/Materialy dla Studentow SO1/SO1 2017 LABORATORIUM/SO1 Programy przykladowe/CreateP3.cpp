#include<windows.h>
#include <stdio.h> 
#include <cstdlib>
#include <cmath>
using namespace std;

void ProgramGlowny(int, char);

int main(int argc, char *argv[]) 		 // CreateP3
{
PROCESS_INFORMATION pi1, pi2;
char cmd1[80] = "Test_BubbleSort  20000 5.5 66.6";
STARTUPINFO si1 = {
   sizeof(si1), NULL,NULL,  "Test_BubbleSort", 500, 370, 420, 250, 
        0, 0,
        0xf2,                   // fill attribute
        STARTF_USEFILLATTRIBUTE | STARTF_USEPOSITION | STARTF_USESIZE, 
        0, 0 ,NULL,NULL,NULL  };

char cmd2[80] = "Test_Fibonacci  40  Fib_Wyniki.asc";
STARTUPINFO si2 = {
   sizeof(si2), NULL,NULL,  "Test_Fibonacci", 40, 370, 420, 280, 0, 0,
        0xe3,                   // fill attribute
        STARTF_USEFILLATTRIBUTE | STARTF_USEPOSITION | STARTF_USESIZE, 
        0, 0,NULL,NULL,NULL  };

CreateProcess(0, cmd1, NULL,NULL,0, CREATE_NEW_CONSOLE, NULL,NULL, &si1, &pi1);
CreateProcess(0, cmd2, NULL,NULL,0, CREATE_NEW_CONSOLE, NULL,NULL, &si2, &pi2);

ProgramGlowny(300, '*'); // 1-szy parametr decyduje o powodzeniu poni¿szego odczytu

puts("------odczyt kontrolny wynikow programu Test_Fibonacci.exe");
long F;
FILE *pF = fopen("Fib_Wyniki.asc", "rt");  
while (!feof(pF)) { fscanf(pF, "%ld", &F); printf("%ld ", F); }
fclose(pF);
puts("\nKoniec MAIN");  
//getchar();
return 0;
}

void ProgramGlowny(int n, char zn)        // d³ugotrwa³e obliczenia
{
for (int k1=0; k1 < n; k1++){   
      for (int k2=0; k2 < 90000; k2++) pow(sin(k1),3.3)* pow(cos(k1),2.2); 
      printf("%c ", zn);
      } puts("");
}

