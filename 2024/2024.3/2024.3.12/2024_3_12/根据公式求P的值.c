#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
float fun(int m, int n)
{
	int i = 1;
	int s1 = 1, s2=1, s3=1;
	float p;
	for (i = 1; i <= m; i++)
	{
		s1 = s1 * i;
	}
	for (i = 1; i <= n; i++)
	{
		s2 = s2 * i;
	}
	for (i = 1; i <= m-n; i++)
	{
		s3 = s3 * i;
	}
	p = (float)s1 / (s2 * s3);
}
int main()
{
	float p = 0;
	int m = 12;
	int n = 8;
	p = fun(m, n);
	printf("%f\n", p);
	return 0;
}