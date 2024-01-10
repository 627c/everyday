#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int ch = fgetc(stdin);
	fputc(ch, stdout);
	return 0;
}