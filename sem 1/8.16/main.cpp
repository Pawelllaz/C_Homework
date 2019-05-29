#include <stdio.h>
#include <stdlib.h>

/*int is_prime(int n,int d)
{
    if(d*d>n)
        return 1;
    else
    {
        int res=n%d!=0;
        if(res==1)
            res=res && is_prime(n,d+1);
        return res;
    }
}*/

int is_prime_rec(int n, int d)
{
	if(d*d>n) return 1;
	if(n%d==0)
    {
        return 0;
    }
    else
    {
        return is_prime_rec(n,d+1);
    }
}
//========================================
int main()
{
	int i,x1,x2;

	printf("Podaj x1: ");
	scanf("%d",&x1);
	printf("Podaj x2: ");
	scanf("%d",&x2);
	for(i=x1;i<=x2;i++)
	{
		if(is_prime_rec(x1,2)==1)
        {
            printf("%d ",x1);
        }
        x1++;
	}

	return 0;
}
