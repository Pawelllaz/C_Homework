#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {

	float a,b,c;

	printf("wpisz kolejna liczbe: ");
    scanf("%f", &b);

	for(;;)
	{
	    if(b==0)
        {
            break;
        }
	    printf("wpisz kolejna liczbe: ");
		scanf("%f", &a);
		if(a==0)
		{
			break;
        }
        c=a-b;
        printf("%f\n", c);

        printf("wpisz kolejna liczbe: ");
		scanf("%f", &b);
        if(b==0)
        {
            break;
        }
        c=b-a;
        printf("%f\n", c);

	}

	return 0;
}
