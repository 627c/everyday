#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void GetMemory(char** p, int num)
{
	*p = (char*)malloc(num);
}
void test()
{
	char* str = NULL;
	GetMemory(&str, 100);
	strcpy(str, "hello");
	printf(str);
	free(str);
	str = NULL;
}
int main()
{
	test();
	return 0;
}