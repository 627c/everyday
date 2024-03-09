#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//将a中的十位和个位依次放在c的十位和千位上，b的十位和个位放在c的个位和百位上
void fun(int a, int b, int* p)
{
	*p = (a / 10) * 10 + (a % 10) * 1000 + (b / 10) + (b % 10) * 100;
}
int main()
{
	int a = 45, b = 12;
	int c = 0;
	int* p = &c;
	fun(a, b, p);
	printf("%d\n", c);
	return 0;
}