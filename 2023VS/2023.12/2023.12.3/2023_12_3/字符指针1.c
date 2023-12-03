#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	char* p = "abcdef";  //"abcdef"是一个常量字符串
	printf("%c\n", *p);
	printf("%s\n", p);
	return 0;
}