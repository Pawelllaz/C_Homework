#include <cstdlib>   
#include <iostream>  
#include <cmath>
using namespace std;

int main(int argc, char *argv[])        // Prog1
{
double x;
   if (argc < 2 ) {cout << "Brak parametrow w " << *argv; 
                   cout << endl; cin.get(); return -1; }
for (int i=1; i < argc; i++) {
     x = atof(argv[i]);  // konwersja ³añcucha na liczbê
     cout <<  "sqrt(" << x << ") = " << sqrt(x) << endl;
     }
cout << "Koniec Prog1";
// cin.get();  
return 0;
}

