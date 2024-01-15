#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int i, j;
	char ch;
	scanf("%d%c%f", &i, &ch, &j);
	printf("%d%2c%7.2f", i, ch, j);
	return 0;
}