#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int fun(char str[])
{
	int n = 0;
	char* p = str;
	for (; *p != '\0'; p++)
	{
		if ((*p != ' ') && ((*(p + 1) == ' ') || (*(p + 1) == '\0')))
		{
			n++;
		}
	}
	return n;
}
int main()
{
	char str[] = "hello";
	printf("%d\n", fun(str));
	return 0;
}