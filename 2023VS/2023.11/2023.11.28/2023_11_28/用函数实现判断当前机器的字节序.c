#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int check_sys()
{
	int a = 1;
	char* pa = &a;
	return *pa;   //返回1，小端；返回0，大端
}
int main()
{
	//返回1，小端
	//返回0，大端
	int ret = check_sys();
	if (ret == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}