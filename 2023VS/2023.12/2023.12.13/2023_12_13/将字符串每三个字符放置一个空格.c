#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	int i, k = 0;
	char a[80], b[110], * p;
	p = a;
	gets(p);
	for (i = 1; *p != '\0'; p++, k++, i++)
	{
		if ((i>1)&&((i-1) % 3 == 0)) { b[k] = ' '; k++; }
		b[k] = *p;
	}
	b[k] = '\0';
	puts(b);
	return 0;
}