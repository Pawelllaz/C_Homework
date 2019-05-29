#pragma once

struct pc {
	char *t;
	int taken;
	float counter;
	int rep;
};
void display(char *t, int a, int b);
void create_chrupki(struct pc *pac, int a, int b, int chrup, int wsk);
int game_menu();
int lvl();
int game(int count_of_chrupki, int moves, int move_by_chrupek, char *imie,int lvl);

