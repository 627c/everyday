#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a[2][3] = { 3,5,7,12,13,6 };
	int b[2][3] = { 4,8,10,6,13,16 };
	int c[2][3] = { 0 };
	int i = 0, j = 0;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
}