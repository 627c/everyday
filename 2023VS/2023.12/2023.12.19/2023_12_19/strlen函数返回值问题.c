#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	//strlen��������ֵΪunsigned int,-3�������޷���������Ȼ������
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