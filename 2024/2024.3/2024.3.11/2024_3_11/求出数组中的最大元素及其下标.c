#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int fun(int a[], int t, int* k)
{
	int max = a[0];
	int i = 0;
	for (i = 0; i < t; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			*k = i;
		}
	}
	return max;
}
int main()
{
	int a[] = { 876,675,896,101,301,401,980,431,451,777 };
	int m = 0;
	int* k = &m;
	int t = sizeof(a) / sizeof(a[0]);
	int max = 0;
	max = fun(a, t, k);
	printf("%d %d\n", *k, max);
	return 0;
}