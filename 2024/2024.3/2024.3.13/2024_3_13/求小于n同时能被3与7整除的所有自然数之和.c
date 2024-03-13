#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
float fun(int n)
{
	float m = 0;
	int i = 0;
	for (i = 21; i <= n; i++)
	{
		if ((i % 3 == 0) && (i % 7 == 0))
		{
			m += i;
		}
	}
	m = sqrt(m);
	return m;
}
int main()
{
	int n = 1000;
	float m = 0;
	m = fun(n);
	printf("%f\n", m);
	return 0;
}