#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int fun(int lim, int a[50])
{
	int i = 0,j=0;
	int count = 0;
	for (i = 2; i <= lim; i++)
	{
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (j == i)
		{
			a[count] = i;
			count++;
		}
	}
	return count;
}
int main()
{
	int a[50] = { 0 };
	int lim;
	scanf("%d", &lim);
	int count = fun(lim, a);
	printf("%d\n", count);
	int i = 0;
	for (i = 0; i < count; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}