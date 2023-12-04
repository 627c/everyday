#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int Add(int x, int y)
{
	return (x + y);
}
int main()
{
	int (*pa)(int, int) = Add;
	printf("%d\n", (*pa)(2, 3));
	return 0;
}