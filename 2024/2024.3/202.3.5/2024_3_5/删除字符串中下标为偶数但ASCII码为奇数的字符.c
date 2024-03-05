#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void fun(char a[], char b[])
{
	int i = 0, j = 0 ;
	for (i = 0; i < strlen(a); i++)
	{
		if ((i % 2 == 0) && ((int)a[i] % 2 == 1))
			continue;
		b[j++] = a[i];
	}
}
int main()
{
	char a[50] = "ABCDEFG12345";
	char b[50] = { 0 };
	fun(a, b);
	int i = 0;
	for (i = 0; i < strlen(b); i++)
	{
		printf("%c", b[i]);
	}
	return 0;
}