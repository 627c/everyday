#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 5
float fun(int a[][N])
{
	int i, j;
	float sum = 0,s;
	int n;
	n = 2 * N + 2 * (N - 2);
	for (j = 0; j < N; j++)
	{
		sum += a[0][j];
		sum += a[N-1][j];
	}
	for (i = 1; i < N - 1; i++)
	{
		sum += a[i][0];
		sum += a[i][N-1];
	}
	s = sum / n;
	return s;
}
int main()
{
	int a[N][N] = { 0,1,2,7,9,1,9,7,4,5,2,3,8,3,1,4,5,6,8,2,5,9,1,4,1 };
	float s = 0;
	s = fun(a);
	printf("%f", s);
	return 0;
}