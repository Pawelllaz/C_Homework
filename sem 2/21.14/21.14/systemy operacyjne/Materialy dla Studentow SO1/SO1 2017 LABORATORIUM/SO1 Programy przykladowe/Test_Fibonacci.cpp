#include <cstdlib>
#include<cstring>
#include <cstdio> 
#include <cmath>
using namespace std;

long Fib(int n)
{ if (n < 2)  return n;
   else return Fib(n - 2) + Fib(n - 1); }

int main(int argc, char *argv[]) 		 // Test Fibonacci
{
char plik[33];
int nData; 
long F;
if (argc <= 1 ) { nData = 40; strcpy(plik, "Fib_Wyniki.asc"); }
else { nData= atoi(argv[1]), strcpy(plik, argv[2]); }
FILE *pF;
if ((pF = fopen(plik, "wt"))== NULL) {
            printf("Blad w:'%s' \n", plik);  return -1; }
for (int n=0; n <= nData; n++) {
     F = Fib(n);  
     fprintf(pF, "%9ld ", F);
     if ((n%4)==0) puts(""); 
     printf("%9ld ", F);
     }
fclose(pF);
printf("\nZapisano w pliku: %s\n", plik);
puts("\nKoniec Test_Fibonacci");
getchar(); 
return 0;
}

