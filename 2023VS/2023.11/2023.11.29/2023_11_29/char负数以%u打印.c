#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	char a = -128;
	//10000000
	printf("%u\n", a);   //%u,以无符号十进制数打印
	//整型提升，前面补1，当作正数
	return 0;
}