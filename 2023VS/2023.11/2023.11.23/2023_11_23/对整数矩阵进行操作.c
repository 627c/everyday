#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a[4][4];
	int i = 0, j = 0;
	int s1 = 0, s2 = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	printf("原矩阵为：\n");
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
	s1 = a[0][0] + a[1][1] + a[2][2] + a[3][3];
	s2 = a[1][1] + a[3][3];
	printf("s1=%d  s2=%d\n", s1, s2);
	int max = a[0][0];
	int m = 0;
	int min = a[0][0];
	int n = 0;
	for (i = 0; i < 4; i++)
	{
		if (max < a[i][i])
		{
			m = i;
			max = a[i][i];
		}
	}
	for (j = 0; j < 4; j++)
	{
		if (min > a[j][j])
		{
			n = j;
			min = a[j][j];
		}
	}
	a[m][m] = min;
	a[n][n] = max;
	printf("新矩阵为：\n");
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}