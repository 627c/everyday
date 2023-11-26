#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//F5启动调试，通常配合F9使用，F9设置断点或者切换断点
//F10逐过程，F11逐语句
int main()
{
	int i = 0;
	for (i = 0; i < 100; i++)
	{
		printf("%d ", i);
	}
	for (i = 0; i < 100; i++)
	{
		printf("%d ", 10-i);
	}
	return 0;
}