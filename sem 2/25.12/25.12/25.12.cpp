#include "stdafx.h"
#include <stdio.h>
//#include <Windows.h>
#define N 1010
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
	struct probka b;
	unsigned char znak;
};
//========================================================================================================
int encode(const char *input, char *txt, const char *output)
{
	if (input == NULL || txt == NULL || output == NULL) return 4;
	union bit_set unia1, unia2;
	FILE *f;
	f = fopen(input, "r");
	if (f == NULL) return 1;
	int counti = 0;
	for (int i = 0; *(input + i) != 0; i++)
	{
		counti++;
	}
	counti -= 5;
	if (*(input + counti) != 'g' && *(input + counti) != 'p')
	{
		fclose(f);
		return 3;
	}
	counti--;
	if (*(input + counti) != 'n' && *(input + counti) != 'p' && *(input + counti) != 'm')
	{
		fclose(f);
		return 3;
	}
	counti--;
	if (*(input + counti) != 'p' && *(input + counti) != 'j' && *(input + counti) != 'b')
	{
		fclose(f);
		return 3;
	}
	counti--;
	if (*(input + counti) != '.')
	{
		fclose(f);
		return 3;
	}
	FILE *g;
	g = fopen(output, "w");
	if (g == NULL)
	{
		fclose(f);
		return 2;
	}
	int liczba, x;
	char enter;
	for (int i = 0; feof(f) == 0; i++)
	{
		unia2.znak = *(txt + i);
		x = fscanf(f, "%d", &liczba);
		if (x != 1) break;
		unia1.znak = liczba;
		unia1.b.a = unia2.b.h;
		fprintf(g, "%d ", unia1.znak);
		x = fscanf(f, "%c", &enter);
		if (x != 1) break;
		if (enter == ' ')
		{
			x = fscanf(f, "%c", &enter);
			if (x != 1) break;
			if (enter == '\n') fprintf(g, "\n");
			else fseek(f, -1, SEEK_CUR);
		}

		x = fscanf(f, "%d", &liczba);
		if (x != 1) break;
		unia1.znak = liczba;
		unia1.b.a = unia2.b.g;
		fprintf(g, "%d ", unia1.znak);
		x = fscanf(f, "%c", &enter);
		if (x != 1) break;
		if (enter == ' ')
		{
			x = fscanf(f, "%c", &enter);
			if (x != 1) break;
			if (enter == '\n') fprintf(g, "\n");
			else fseek(f, -1, SEEK_CUR);
		}


		x = fscanf(f, "%d", &liczba);
		if (x != 1) break;
		unia1.znak = liczba;
		unia1.b.a = unia2.b.f;
		fprintf(g, "%d ", unia1.znak);
		x = fscanf(f, "%c", &enter);
		if (x != 1) break;
		if (enter == ' ')
		{
			x = fscanf(f, "%c", &enter);
			if (x != 1) break;
			if (enter == '\n') fprintf(g, "\n");
			else fseek(f, -1, SEEK_CUR);
		}

		x = fscanf(f, "%d", &liczba);
		if (x != 1) break;
		unia1.znak = liczba;
		unia1.b.a = unia2.b.e;
		fprintf(g, "%d ", unia1.znak);
		x = fscanf(f, "%c", &enter);
		if (x != 1) break;
		if (enter == ' ')
		{
			x = fscanf(f, "%c", &enter);
			if (x != 1) break;
			if (enter == '\n') fprintf(g, "\n");
			else fseek(f, -1, SEEK_CUR);
		}

		x = fscanf(f, "%d", &liczba);
		if (x != 1) break;
		unia1.znak = liczba;
		unia1.b.a = unia2.b.d;
		fprintf(g, "%d ", unia1.znak);
		x = fscanf(f, "%c", &enter);
		if (x != 1) break;
		if (enter == ' ')
		{
			x = fscanf(f, "%c", &enter);
			if (x != 1) break;
			if (enter == '\n') fprintf(g, "\n");
			else fseek(f, -1, SEEK_CUR);
		}

		x = fscanf(f, "%d", &liczba);
		if (x != 1) break;
		unia1.znak = liczba;
		unia1.b.a = unia2.b.c;
		fprintf(g, "%d ", unia1.znak);
		x = fscanf(f, "%c", &enter);
		if (x != 1) break;
		if (enter == ' ')
		{
			x = fscanf(f, "%c", &enter);
			if (x != 1) break;
			if (enter == '\n') fprintf(g, "\n");
			else fseek(f, -1, SEEK_CUR);
		}

		x = fscanf(f, "%d", &liczba);
		if (x != 1) break;
		unia1.znak = liczba;
		unia1.b.a = unia2.b.b;
		fprintf(g, "%d ", unia1.znak);
		x = fscanf(f, "%c", &enter);
		if (x != 1) break;
		if (enter == ' ')
		{
			x = fscanf(f, "%c", &enter);
			if (x != 1) break;
			if (enter == '\n') fprintf(g, "\n");
			else fseek(f, -1, SEEK_CUR);
		}

		x = fscanf(f, "%d", &liczba);
		if (x != 1) break;
		unia1.znak = liczba;
		unia1.b.a = unia2.b.a;
		fprintf(g, "%d ", unia1.znak);
		x = fscanf(f, "%c", &enter);
		if (x != 1) break;
		if (enter == ' ')
		{
			x = fscanf(f, "%c", &enter);
			if (x != 1) break;
			if (enter == '\n') fprintf(g, "\n");
			else fseek(f, -1, SEEK_CUR);
		}
		if (*(txt + i) == '\0') break;
	}
	for (; feof(f) == 0;)
	{
		x = fscanf(f, "%d", &liczba);
		if (x != 1) break;
		unia1.znak = liczba;
		unia1.b.a = 0;
		fprintf(g, "%d ", unia1.znak);
		x = fscanf(f, "%c", &enter);
		if (x != 1) break;
		if (enter == ' ')
		{
			x = fscanf(f, "%c", &enter);
			if (x != 1) break;
			if (enter == '\n') fprintf(g, "\n");
			else fseek(f, -1, SEEK_CUR);
		}
	}
	fclose(f);
	fclose(g);
	return 0;
}
//=========================================================================================================
int decode(const char * filename, char *txt, int size)
{
	if (filename == NULL || txt == NULL) return 2;
	if (size <= 0) return 2;
	FILE *f;
	f = fopen(filename, "r");
	if (f == NULL) return 1;

	union bit_set unia1, unia2;
	int x, liczba, counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (feof(f) != 0) break;
		x = fscanf(f, "%d", &liczba);
		if (x != 1) break;
		unia1.znak = liczba;
		unia2.b.h = unia1.b.a;
		counter++;

		if (feof(f) != 0) break;
		x = fscanf(f, "%d", &liczba);
		if (x != 1) break;
		unia1.znak = liczba;
		unia2.b.g = unia1.b.a;
		counter++;
		if (feof(f) != 0) break;
		x = fscanf(f, "%d", &liczba);
		if (x != 1) break;
		unia1.znak = liczba;
		unia2.b.f = unia1.b.a;
		counter++;
		if (feof(f) != 0) break;
		x = fscanf(f, "%d", &liczba);
		if (x != 1) break;
		unia1.znak = liczba;
		unia2.b.e = unia1.b.a;
		counter++;
		if (feof(f) != 0) break;
		x = fscanf(f, "%d", &liczba);
		if (x != 1) break;
		unia1.znak = liczba;
		unia2.b.d = unia1.b.a;
		counter++;
		if (feof(f) != 0) break;
		x = fscanf(f, "%d", &liczba);
		if (x != 1) break;
		unia1.znak = liczba;
		unia2.b.c = unia1.b.a;
		counter++;
		if (feof(f) != 0) break;
		x = fscanf(f, "%d", &liczba);
		if (x != 1) break;
		unia1.znak = liczba;
		unia2.b.b = unia1.b.a;
		counter++;
		if (feof(f) != 0) break;
		x = fscanf(f, "%d", &liczba);
		if (x != 1) break;
		unia1.znak = liczba;
		unia2.b.a = unia1.b.a;
		counter++;
		*(txt + i) = unia2.znak;
	}
	if (counter % 8 != 0)
	{
		fclose(f);
		return 3;
	}
	fclose(f);
	return 0;
}
//==========================================================================================================
int main()
{
	char litera,a;
	char nazwa_pliku_in[30], nazwa_pliku_out[30];
	printf(": ");
	scanf("%c", &litera);
	scanf("%c", &a);
	if (litera == 'e' || litera == 'E')
	{
		char tekst[N];
		printf("podaj tekst: ");
		scanf("%1009[^\n]s", tekst);
		printf("podaj wejscie: ");
		scanf("%29s", nazwa_pliku_in);
		printf("podaj wyjscie: ");
		scanf("%29s", nazwa_pliku_out);
		int x = encode(nazwa_pliku_in, tekst, nazwa_pliku_out);
		if (x == 0) printf("File saved");
		else if (x == 1)
		{
			printf("File not found");
			return x;
		}
		else if (x == 2)
		{
			printf("Couldn't create file");
			return x;
		}
		else if (x == 3)
		{
			printf("File corrupted");
			return x;
		}
		else printf("error");
	}
	else if (litera == 'd' || litera == 'D')
	{
		char nazwa_pliku[30], tekst[N];
		printf("podaj nazwe pliku: ");
		scanf("%29s", nazwa_pliku);
		int x = decode(nazwa_pliku, tekst, N);
		if (x == 0)
		{
			for (int i = 0; *(tekst + i) != 0; i++)
			{
				printf("%c", *(tekst + i));
			}
		}
		else if (x == 1)
		{
			printf("File not found");
			return x;
		}
		else if (x == 3)
		{
			printf("File corrupted");
			return x;
		}
	}
	else printf("Incorrect input");
	//system("PAUSE");
	return 0;
}