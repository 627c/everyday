#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void fun(int m, int k, int xx[])
{
	int i = 0;
	int count = 0;
	int j = 0;
	int n = 0;
	for (i = m + 1;; i++)
	{
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
				break;
		}
		if (j >= i)
		{
			count++;
			xx[n++] = i;
		}
		if (count == 5)
			break;
	}
}
int main()
{
	int m = 17;
	int k = 5;
	int xx[5];
	fun(m, k, xx);
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		printf("%d ", xx[i]);
	}
	return 0;
}