#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void fun(char* a)
{
	int i = 0;
	char* p = a;
	while (*p)
	{
		if (*p != ' ')
		{
			a[i++] = *p;
		}
		p++;
	}
	a[i] = '\0';
	printf("%s", a);
}
int main()
{
	char a[50];
	gets(a);//不能用scanf,空格为结束符
	fun(a);
	return 0;
}