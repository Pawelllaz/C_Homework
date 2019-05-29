#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	/*
	double s;
	int n,a;
	
	printf("wprowadz ilosc wyrazow szeregu:\n");
	scanf("%lg", &a);
	
	if(a>=1)
	{
		for (n=1;n<a;n++)
		{
		s += 1 / (n*(n+1));
		}
	}
	printf("%.2lg %d %d", s,n,a);
	*/
	
	const double eps=0.0001;
	int n;
	double w,s;
	
	s=0;
	for(n=1;;n++)
	{
		w=(double)1/(n*(n+1));
		if(w<=eps) break;
		s+=w;
	}
	printf("suma=%f n=%d", s,n);
	return 0;
}
