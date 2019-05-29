#include <windows.h>  			// Prog2    uruchomiony konsolowo w Dev-C++
int WINAPI WinMain(HINSTANCE  hInstance,    HINSTANCE  hPrevInstance,
                   LPSTR  lpCmdLine,   int uCmdShow)
{ 
LPCTSTR tekst="Opis dzialania";
  MessageBoxEx(NULL, tekst, "Tytul Nowego Okna", IDABORT, 0);
  return 0;
}
