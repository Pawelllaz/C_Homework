#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include "head.h"
#define print printf("\tPACMAN\nzasady gry:\n masz 40 ruchow\n kazdy chrupek (*) daje 5 ruchow\n im wiecej zebranych * tym wyzszy wynik\n porusza sie klawiszami wsad pozycja (0)\n (e) konczy gre\n\n\tgracz: %s\n",imie);
#define deb printf("debug\n");
#define kres printf("|");

int main()
{
	srand(time(NULL));
	int choice, check, game_info;
	char *imie= (char*)malloc(30);
	FILE *f=0;
	while (1)
	{
		choice = game_menu();
		switch (choice)
		{ 
		case 1:
			system("cls");
			printf("wpisz imie gracza: ");
			fflush(stdin);
			scanf("%29s", imie);
			system("cls");
			game_info = lvl();
			//printf("imie: %d %s", game_info, imie);
			switch (game_info)
			{
			case 1:
				check = game(10, 50, 5, imie,1);
				break;
			case 2:
				check = game(10, 40, 4, imie,2);
				break;
			case 3:
				check = game(10, 35, 3, imie,3);
				break;
			}
			break;
		case 2:
			f = fopen("wyniki.txt", "r");
			system("cls");
			if (f == NULL)
			{
				printf("plik ze statystykami nie istnieje");
				_getch();
				continue;
			}
			char odczyt;
			while (fscanf(f, "%c", &odczyt) != EOF)
			{
				printf("%c", odczyt);
			}
			fclose(f);
			printf("\ndowolny klawisz aby powrocic");
			_getch();
			system("cls");
			break;
		case 3:
			printf("Pawel Lazicki\ndowolny klawisz aby powrocic");
			_getch();
			break;
		case 4:
			printf("wyjscie");
			for (int i = 0; i < 5; i++)
			{
				printf(".");
				Sleep(250);
			}
			return 0;
		case 0:
			return 0;
			break;
		}
	}
	
	return 0;
}