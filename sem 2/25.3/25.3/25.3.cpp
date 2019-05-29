#include "stdafx.h"
#include <stdio.h>
//#include <Windows.h>

struct probka {
	unsigned char a : 1;
	unsigned char b : 1;
	unsigned char c : 1;
	unsigned char d : 1;
	unsigned char e : 1;
	unsigned char f : 1;
	unsigned char g : 1;
	unsigned char h : 1;
};

union bit_set {
	struct probka b[4];
	unsigned int liczba;
};

int main() {
	union bit_set a;
	printf(": ");
	unsigned int liczba;
	int counter = 0;
	scanf("%u", &liczba);
	a.liczba = liczba;
	for (int i = 0; i < 4; i++)
	{
		if ((a.b+i)->a) counter++;
		if ((a.b+i)->b) counter++;
		if ((a.b+i)->c) counter++;
		if ((a.b+i)->d) counter++;
		if ((a.b+i)->e) counter++;
		if ((a.b+i)->f) counter++;
		if ((a.b+i)->g) counter++;
		if ((a.b+i)->h) counter++;
	}
	if (counter % 2 == 0) printf("YES");
	else printf("NO");
	//system("PAUSE");
	return 0;
}