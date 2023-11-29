#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	char a = -1;
	//-1 补码是全1
	//11111111 8个比特位，低8位
	signed char b = -1;
	//11111111 8个比特位
	unsigned char c = -1;
	//11111111
	printf("a=%d,b=%d,c=%d", a, b, c);   //整型提升 有符号数前面补符号位，无符号数前面补0，对补码进行操作
	return 0;
}