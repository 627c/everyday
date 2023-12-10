#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct Test
{
	int Num;
	char* pcNum;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;//创建一个结构体指针变量p
//假设p的值为0x100000.如下表达式的值分别是多少？
//已知，结构体Test类型的变量大小是20个字节
int main()
{
	p = (struct Test*)0x100000;
	printf("%p\n", p + 0x1);//跳过一个结构体，20个字节，0x100000+20=0x100014
	printf("%p\n", (unsigned long)p + 0x1);//整型+1，强制类型转换
	printf("%p\n", (unsigned int*)p + 0x1);//强制转换为无符号整型指针，+1跳过4个字节
	return 0;
}