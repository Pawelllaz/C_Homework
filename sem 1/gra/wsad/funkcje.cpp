#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include <string.h>
#include "head.h"
#define print printf("\tPACMAN\nzasady gry:\n masz %d ruchow\n kazdy chrupek @ daje %d ruchow\n im wiecej zebranych * tym wyzszy wynik\n porusza sie klawiszami wsad pozycja (8)\n (e) konczy gre\n\n\tgracz: %s\n",moves,move_by_chrupek,imie);
#define deb printf("debug\n");
#define kres printf("|");

int game(int count_of_chrupki, int moves, int move_by_chrupek, char *imie, int lvl)
{
	FILE *f;
	f = fopen("wyniki.txt", "a");
	if (f == NULL)
	{
		printf("blad otwarcia pliku z wynikami");
		_getch();
		return 1;
	}
	print

	const int chrupki = count_of_chrupki, ile_ruchow = moves, ile_dostaniesz = move_by_chrupek;			//zmienne
	const int a = 10, b = 20;
	struct pc *pac;

	pac = (struct pc*)malloc(sizeof(struct pc));		//alokacja
	pac->t = (char*)malloc(a*b);
	pac->counter = 0;						//przypisanie stalych
	pac->taken = 0;
	pac->rep = chrupki;
	for (int i = 0; i < a; i++)				//tworzenie mapy
		for (int j = 0; j < b; j++)
			*(pac->t + j + i * b) = '=';
	char in;
	int wsk = ((a*b) / 2) + (b / 2);			//stworzenie kursora
	*(pac->t + wsk) = '8';

	create_chrupki(pac, a, b, chrupki, wsk);		//generuj chrupki
	display(pac->t, a, b);

	for (int i = 0;; i++)					// petla gry
	{
		printf("i: %d", i);
		in = _getch();						// blad w funkcji wczytuje jednoczesnie wcisniecie  i puszczenie klawisza
		system("cls");
		printf("i=%d\n", i);
		switch (in)
		{
		case'w':
			*(pac->t + wsk) = '=';
			if (wsk - b >= 0)
			{
				if (*(pac->t + wsk - b) == '@')
				{
					pac->taken++;
					pac->rep--;
					pac->counter -= ile_dostaniesz;
				}
				wsk -= b;
			}
			*(pac->t + wsk) = '8';
			break;
		case's':
			*(pac->t + wsk) = '=';
			if (wsk + b < a*b)
			{
				if (*(pac->t + wsk + b) == '@')
				{
					pac->taken++;
					pac->rep--;
					pac->counter -= ile_dostaniesz;
				}
				wsk += b;
			}
			*(pac->t + wsk) = '8';
			break;
		case'a':
			*(pac->t + wsk) = '=';
			if (wsk%b != 0)
			{
				if (*(pac->t + wsk - 1) == '@')
				{
					pac->taken++;
					pac->rep--;
					pac->counter -= ile_dostaniesz;
				}
				wsk -= 1;
			}
			*(pac->t + wsk) = '8';
			break;
		case'd':
			*(pac->t + wsk) = '=';
			if ((wsk + 1) % b != 0)
			{
				if (*(pac->t + wsk + 1) == '@')
				{
					pac->counter -= ile_dostaniesz;
					pac->taken++;
					pac->rep--;
				}
				wsk += 1;
			}
			*(pac->t + wsk) = '8';
			break;
		case'e':
			printf("wyjscie");
			free(pac->t);
			free(pac);
			free(imie);
			fclose(f);
			for (int i = 0; i < 5; i++)
			{
				printf(".");
				Sleep(250);
			}
			return 0;
		}
		print
		display(pac->t, a, b);
		pac->counter += 2;
		pac->counter -= 1.5;
		printf("zostalo %.0f ruchow\n", ile_ruchow - pac->counter);
		if (pac->counter >= ile_ruchow)
		{
			printf("koniec ruchow\n");
			printf("twoj wynik: %d\nzapisywanie", pac->taken);
			Sleep(3000);
			if(lvl==1) fprintf(f, "wynik gracza %s = %d, poziom latwy,  %s %s\n", imie, pac->taken, __TIME__, __DATE__);
			if (lvl == 2) fprintf(f, "wynik gracza %s = %d, poziom sredni,  %s %s\n", imie, pac->taken, __TIME__, __DATE__);
			if (lvl == 3) fprintf(f, "wynik gracza %s = %d, poziom trudny,  %s %s\n", imie, pac->taken, __TIME__, __DATE__);
			for (int j = 0; j < 10; j++)
			{
				printf(".");
				Sleep(100);
			}
			free(imie);
			free(pac->t);
			free(pac);
			fclose(f);
			fflush(stdin);				// nie dziala ani fflush ani rewind
			rewind(stdin);
			printf(" kliknij aby wyjsc");
			_getch();
			return 0;
		}
		//printf("\npac->rep: %d\n", pac->rep);
		if (pac->rep < 1)
		{
			create_chrupki(pac, a, b, chrupki, wsk);
			pac->rep = chrupki;
		}
	}
	free(pac->t);
	free(pac);
	free(imie);
	fclose(f);
}
int lvl()
{
	char *level = (char*)malloc(10);
	printf("wybierz poziom trudnosci: latwy, sredni czy trudny?");
	scanf("%9s", level);
	//printf("lev: %s", level);
	if (strcmp(level,"latwy")==0)
	{
		free(level);
		return 1;
	} 
	else if (strcmp(level, "sredni") == 0)
	{
		free(level);
		return 2;
	}
	else if (strcmp(level, "trudny") == 0)
	{
		free(level);
		return 3;
	}
	return 0;
}
int game_menu()
{
	int choice = 0, x;
	system("cls");
	printf("\tPACMAN\n1. gra\n2. statystyki\n3. autor\n4. wyjscie\n");
	x = scanf("%d", &choice);
	if (x != 1)
	{
		printf("blad");
		for (int i = 0; i < 5; i++)
		{
			printf(".");
			Sleep(250);
		}
		return 0;
	}
	else if (choice < 1 || choice>4)
	{
		printf("blad");
		for (int i = 0; i < 5; i++)
		{
			printf(".");
			Sleep(250);
		}
		return 0;
	}
	return choice;
}
void display(char *t, int a, int b)
{
	kres
		for (int i = 0; i < b; i++)
			printf("| ");
	kres
		printf("\n");
	for (int i = 0; i < a; i++)
	{
		kres
			for (int j = 0; j <b; j++)
				printf("%c ", *(t + j + i * b));
		kres
			printf("\n");
	}
	kres
		for (int i = 0; i < b; i++)
			printf("| ");
	kres
		printf("\n");
}
void create_chrupki(struct pc *pac, int a, int b, int chrup, int wsk)
{
	int randi, spr=0;
	int *random_numbers = (int*)malloc(sizeof(int)*chrup);
	for (int i = 0; i < chrup; i++)
	{
		randi = rand() % (a*b);
		random_numbers[i] = randi;
		if (i > 0)
		{
			for (int j = i - 1; j >= 0; j--)
				if (random_numbers[j] == randi) spr++;
			if (spr > 0)
			{
				spr = 0;
				i--;
				continue;
			}
		}
		if (randi == wsk || randi < 0 || randi>199)
		{												 
			i--;
			continue;
		}
		*(pac->t + randi) = '@';
	}
	free(random_numbers);
}