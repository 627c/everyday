#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	//写一段代码告诉我们当前机器的字节序是什么，大端存储或小端存储
	int a = 20;
	//0x 00 00 00 14
	//大端 00 00 00 14
	//小端 14 00 00 00
	char* pa = &a; //a的首地址，取第一个字节的内容
	if (*pa == 20)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}