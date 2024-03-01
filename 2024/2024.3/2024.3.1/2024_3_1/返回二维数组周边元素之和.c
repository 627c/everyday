#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int fun(int a[][5])
{
	int i = 0, j = 0;
	int s = 0;
	for (j = 0; j < 5; j++)
	{
		s += a[0][j];
		s += a[3][j];
	}
	for (i = 1; i < 3; i++)
	{
		s += a[i][0];
		s += a[i][4];
	}
	return s;
}
int main()
{
	int a[][5] = { 1,3,5,7,9,2,9,9,9,4,6,9,9,9,8,1,3,5,7,0 };
	int s = fun(a);
	printf("%d", s);
	return 0;
}