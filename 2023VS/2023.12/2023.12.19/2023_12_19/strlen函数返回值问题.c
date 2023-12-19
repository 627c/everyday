#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	//strlen函数返回值为unsigned int,-3被当作无符号数，自然是正数
	if (strlen("abc") - strlen("abcdef") > 0)
	{
		printf("haha\n");
	}
	else
	{
		printf("hehe\n");
	}
	return 0;
}