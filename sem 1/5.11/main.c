#include <stdio.h>
#include <stdlib.h>

/*Napisz program pobieraj�cy od u�ytkownika 10 liczb ca�kowitych, po dwie naraz, kt�ry zapisuje je do kolejnych element�w tablicy.
Po pobraniu tych liczb wy�wietl je na ekranie, ka�d� w osobnym wierszu razem z informacj� o jej parzysto�ci w formie opisu �pierwsza� albo �zlozona�.
Ka�dy opis (wyr�wnany do lewej) musi by� poprzedzony odpowiadaj�c� mu warto�ci� liczbow� w danym wierszu. Wszystkie wydruki zako�cz znakiem nowej linii.*/

int main() {

	printf("wpisz liczbe calkowita:");
	int tab[10];
	int i,a,c,spr;
	for(i=0;;i++)
	{
		c=scanf("%d %d", &tab[i],&tab[i+1]);
		if(c!=2)
        {
            printf("error");
            return 2;
            break;
        }

        printf("%d ", tab[i]);
        spr=0;
        for(a=2;a<=10000;a++)
        {
            if(tab[i]%a!=0 && a!=i)
            {
                spr++;
            }
            if(tab[i]==a)
                break;
        }
        if(spr==tab[i]-2)
            printf("pierwsza\n");
        else
            printf("zlozona\n");
        printf("%d ", tab[i+1]);
        spr=0;
        for(a=2;a<=10000;a++)
        {
            if(tab[i+1]%a!=0 && a!=i+1)
            {
                spr++;
            }
            if(tab[i+1]==a)
                break;
        }
        if(spr==tab[i+1]-2)
            printf("pierwsza\n");
        else
            printf("zlozona\n");

		if(i==8)
		{
			break;
		}
		i++;
	}

	return 0;
}
