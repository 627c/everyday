#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define M 3
#define N 4
//一维数组中元素的个数存放在形参n所指的存储单元中
void fun(int a[M][N], int b[100], int* n)
{
	int i = 0, j = 0, k=0 ;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			b[k++] = a[i][j];
		}
	}
	*n = k;
}
int main()
{
	int a[M][N] = { 33,33,33,33,44,44,44,44,55,55,55,55 };
	int b[100];
	int k = 0;
	int* n = &k;
	fun(a,b,n);
	int i = 0, j = 0;
	for (i = 0; i < *n; i++)
	{
		printf("%d ", b[i]);
	}
	printf("\n%d\n", k);
	return 0;
}