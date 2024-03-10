#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void fun(int x, int pp[], int* n)
{
	int i = 1;
	int j = 0;
	for (i = 1; i <= x; i++)
	{
		if ((x % i == 0) && (i % 2 == 1))
		{
			*n = *n + 1;
			pp[j++] = i;
		}
	}
}
int main()
{
	int x = 30;
	int pp[10];
	int a = 0;
	int* n = &a;
	fun(x, pp, n);
	printf("%d\n", a);
	int i = 0;
	for (i = 0; i < a; i++)
		printf("%d ", pp[i]);
	return 0;
}