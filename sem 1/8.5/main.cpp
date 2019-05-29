#include <stdio.h>
#include <math.h>

int is_divisible_by_11(int number)
{
	int sumanp=0;
	int sumaparz=0;

	if(number<10)
	{
		if(number==0)
        {
            return 1;
        }
		else
		{
		    return 0;
		}
	}

	while(number>0)
    {
        sumanp+=number%10;
        number/=10;
        sumaparz+=number%10;
        number/=10;
    }

    return is_divisible_by_11(fabs(sumanp-sumaparz));
}
int main()
{
    int liczba;

    printf("Podaj liczbe: ");
    scanf("%d", &liczba);

    if(is_divisible_by_11(liczba))
    {
    	printf("TAK");
	}
	else printf("NIE");

    return 0;
}
