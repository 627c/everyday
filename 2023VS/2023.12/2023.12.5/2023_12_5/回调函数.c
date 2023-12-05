#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void print(char* str)
{
	printf("hehe\n");
}
void test(void(*p)(char*))
{
	printf("test\n");
	p("jiangnan");
}
int main()
{
	test(print);
	return 0;
}