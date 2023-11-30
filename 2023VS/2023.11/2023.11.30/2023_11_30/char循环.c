#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	unsigned char i = 0;  //范围在0-255
	for (i = 0; i <= 255; i++)    //i<=255,恒成立，死循环
	{
		printf("hello world\n");
	}
	return 0;
}