#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>
int main()
{
	char ch = '2';
	int ret = isdigit(ch);//Êý×Ö×Ö·û
	printf("%d\n", ret);
	char ch1 = toupper('q');
	putchar(ch1);
	return 0;
}