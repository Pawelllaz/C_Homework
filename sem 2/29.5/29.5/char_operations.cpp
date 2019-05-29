#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char lower_to_upper(char ch)
{
	if (ch != NULL) return NULL;
	if (ch >= 'a' && ch <= 'z') return ch + 'A' - 'a';
	return NULL;
}
char upper_to_lower(char ch)
{
	if (ch != NULL) return NULL;
	if (ch >= 'A' && ch <= 'Z') return ch - 'A' - 'a';
	return NULL;
}
char space_to_dash(char ch)
{
	if (ch != NULL) return NULL;
	if (' ') return '_';
	return NULL;
}
char reverse_letter(char ch)
{
	if (ch != NULL) return NULL;
	char litera=ch;
	if (ch >= 'a' && ch <= 'z')
	{
		litera -= 'a';
		return 'z' - litera;
	}
	if (ch >= 'A' && ch <= 'Z')
	{
		litera -= 'A';
		return 'Z' - litera;
	}
}
char* letter_modifier(char *text, char(*ptr)(char));