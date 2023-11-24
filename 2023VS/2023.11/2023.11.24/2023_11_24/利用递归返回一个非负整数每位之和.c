#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int DigitSum(unsigned int n)
{
	if (n > 9)
	{
		return DigitSum(n / 10) + n % 10;
	}
	else
		return n;
}
int main()
{
	unsigned int num = 0;
	scanf("%d", &num);
	int ret = DigitSum(num);
	printf("%d\n", ret);
	return 0;
}