#include "stdafx.h"
#include <stdio.h>
//#include <conio.h>
#define N 1010
int message_compression(char* txt)
{
	if (txt == NULL) return -1;
	int counter = 0, licznik = 0,counter2=0;
	for (int i = 0; *(txt + i)!=0; i++)
	{
		if (*(txt + i) == 10) break;
		licznik++;
		if ((*(txt + i) >= '!' && *(txt + i) < '0') || (*(txt + i) > '9' && *(txt + i) < 'A') || (*(txt + i) > 'Z' && *(txt + i) < 'a') || (*(txt + i) > 'z' && *(txt + i) <= '~') || *(txt + i) == ' ')
		{
			//printf("%d %c\n", *(txt + i), *(txt + i));
			counter++;
		}
	}
	for (int i = 0; *(txt + i) != 0; i++)
	{
		if (*(txt + i) == 10) break;
		for (;;)
		{
			if ((*(txt + i) >= '!' && *(txt + i) < '0') || (*(txt + i) > '9' && *(txt + i) < 'A') || (*(txt + i) > 'Z' && *(txt + i) < 'a') || (*(txt + i) > 'z' && *(txt + i) <= '~') || *(txt + i) == ' ')
			{
				counter2++;
				if (*(txt + i + 1) >= 'a' && *(txt + i + 1) <= 'z') *(txt + i+1) -= 32;

				for (int j = i; *(txt + j + 1) != 0; j++)
				{
					//if (*(txt + j) == ' ' || *(txt + j) == '-' || *(txt + j) == ',' || *(txt + j) == '"' || *(txt + j) == '.' || *(txt + j) == 96 || *(txt + j) == 39) j++;
					*(txt + j) = *(txt + j + 1);
				}
			}
			else break;
		}
	}
	//printf("%d", counter);
	*(txt + licznik - counter) = 0;																																																																																	counter += 3;
	return counter2;
}

int main()
{
	char txt1[N];
	char *q_txt1 = txt1;
	printf("wpisz tekst:\n");
	fgets(txt1, N, stdin);
	
	if (message_compression(txt1))
	{
		for (int i = 0; *(q_txt1 + i) != 0; i++)
		{
			//if (*(q_txt1 + i) == 10) break;
			printf("%c", *(q_txt1 + i));
		}
	}
	//_getch();
	return 0;
}