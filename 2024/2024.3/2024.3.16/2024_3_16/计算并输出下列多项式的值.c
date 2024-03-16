#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
double fun(int n)
{
	double s = 0;
	int i = 1;
	for (i = 1; i <= n; i++)
	{
		s += 1.0 / (i * (i + 1));
	}
	return s;
}
int main()
{
	double s = 0;
	int n = 10;
	s = fun(n);
	printf("%lf\n", s);
	return 0;
}