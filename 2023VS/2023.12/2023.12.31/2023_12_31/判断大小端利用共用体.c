#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int check_sys()
{
	union Un
	{
		char c;
		int i;
	}u;
	u.i = 1;
	return u.c;
}
int main()
{
	//int a = 0x11223344; //高字节----低字节
	//低地址----------高地址
	//11 22 33 44   大端字节序存储
	//44 33 22 11   小端字节序存储
	//讨论一个数据，放在内存中的字节顺序
	//大小端字节序问题
	int ret = check_sys();
	if (1 == ret)
	{
		printf("小端字节序存储\n");
	}
	else
	{
		printf("大端字节序存储\n");
	}
	return 0;
}