#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
char* my_strcat(char a[], char b[])
{
	char* p = a;
	int len = strlen(a);
	int i, j;
	for (i = len, j = 0; b[j] != '\0'; i++, j++)
	{
		a[i] = b[j];
	}
	a[i] = '\0';
	return p;
}
int main()
{
	char a[40];
	char b[20];
	gets(a);
	gets(b);
	printf("%s\n", my_strcat(a,b));
	return 0;
}