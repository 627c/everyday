#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void test(void)
{
	char* str = (char*)malloc(100);
	strcpy(str, "hello");
	free(str);      //free�ͷ�strָ��Ŀռ�󣬲������str��ΪNULL
	if (str != NULL)
	{
		strcpy(str, "world");     //���ֺܴ����⣬�Ƿ������ڴ�
		printf(str);
	}
}
int main()
{
	test();
	return 0;
}