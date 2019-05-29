#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4

int main(void) {
	
	float a [N] [N], b [N] [N], c [N] [N], k[N][N], h[N][N], q[N][N];
	int i,t;
	srand (time(0));
	
	printf("trzy macierze:\n\n");
	for(i=0;i<N;i++)
	{
		for(t=0;t<N;t++)
		{
			double r=rand();
			double d=rand();
			a[i][t] = d;
			b[i][t] = r;
			if(i==t)
			{
				c[i][t] = 1;
				
			}
			else 
			{
				c[i][t] = 0;
			}
		}
	}
	for(i=0;i<N;i++)
	{
		for(t=0;t<N;t++)
		{
			printf("%8.1f ", a[i][t]);
		}
	printf("\n");
	}
	printf("\n\n");
	for(i=0;i<N;i++)
	{
		for(t=0;t<N;t++)
		{
			printf("%8.1f ", b[i][t]);
		}
	printf("\n");
	}
	for(i=0;i<N;i++)
	{
		for(t=0;t<N;t++)
		{
			printf("%8.0f ", c[i][t]);
		}
	printf("\n");
	}
	printf("\n\n");
	for(i=0;i<N;i++)
	{
		for(t=0;t<N;t++)
		{
			k[i][t] = a[i][t] + b[i][t];
		}
	}
	printf("A + B\n");
	for(i=0;i<N;i++)
	{
		for(t=0;t<N;t++)
		{
			printf("%8.1f ", k[i][t]);
		}
	printf("\n");
	}
	printf("\nA - B");
	for(i=0;i<N;i++)
	{
		for(t=0;t<N;t++)
		{
			h[i][t] = a[i][t] - b[i][t];
		}
	}
	printf("\n");
	for(i=0;i<N;i++)
	{
		for(t=0;t<N;t++)
		{
			printf("%8.1f ", h[i][t]);
		}
	printf("\n");
	}
	printf("\nA * B\n\n");
	for(i=0;i<N;i++)
	{
		for(t=0;t<N;t++)
		{
			q[i][t] = a[i][t] * b[t][i];
		}
	}
	for(i=0;i<N;i++)
	{
		for(t=0;t<N;t++)
		{
			printf("%12.1f ", q[i][t]);
		}
	printf("\n");
	}
	
	
	return 0;
}
