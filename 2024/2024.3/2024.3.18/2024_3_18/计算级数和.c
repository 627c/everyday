#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
double fun(double x, int n)
{
	double s = 1.0;
	int i = 1;
	int m = 1;
	for (i = 1; i <= n; i++)
	{
		m = m * i;
		s += pow(x,i) / m;
	}
	return s;
}
int main()
{
	double x = 0.3;
	int n = 10;
	double s = 0;
	s = fun(x, n);
	printf("%lf\n", s);
	return 0;
}