#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
float fun(double h)
{
	//float s = 0;
	//int x = 0;
	//s = (int)(h * 1000);
	//x = (int)s % 10;
	//if (x >= 5)
	//{
	//	s += 10;
	//}
	//s = (int)s / 10;
	//s = s / 100;
	//return s;
	int tmp = (int)(h * 1000 + 5) / 10;
	return (float)tmp / 100.0;
}
int main()
{
	double h = 0;
	scanf("%lf", &h);
	float s = fun(h);
	printf("%lf", s);
	return 0;
}