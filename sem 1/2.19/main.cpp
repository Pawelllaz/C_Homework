#include <stdio.h>
#include <stdlib.h>

int main()
{
	char t[10];
	int i;

	printf("wpisz tekst: ");
	fgets(t, 10, stdin);

	for (i = 0; i < 5; i++)
	{
		if (t[i] >= 'a' && t[i] <= 'z')
		{
			t[i]-=32;
		}
	}

	for(i=0;i<5;i++)
    {
        printf("%c", t[i]);
    }
	return 0;
}
