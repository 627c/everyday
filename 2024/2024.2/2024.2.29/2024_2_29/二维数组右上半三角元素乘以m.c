#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 3
void fun(int a[][N], int m)
{
	//int (*p)[N] = &(a[0]);
	int i = 0, j = 0;
	for (i = 0; i < N; i++)
	{
		for (j = i; j < N; j++)
		{
			//*(p[i]+j) = 2 * a[i][j];
			a[i][j] = 2 * a[i][j];
		}
	}
}
int main()
{
	int m = 2;
	int a[N][N] = { 1,9,7,2,3,8,4,5,6 };
	fun(a, m);
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}