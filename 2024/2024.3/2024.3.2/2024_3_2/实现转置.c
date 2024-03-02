#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void fun(int a[][3])
{
	int i = 0, j = 0;
	int tmp = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = i; j < 3; j++)
		{
			tmp = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = tmp;
		}
	}
}
int main()
{
	int a[3][3] = { 100,200,300,400,500,600,700,800,900 };
	fun(a);
	int i = 0, j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}