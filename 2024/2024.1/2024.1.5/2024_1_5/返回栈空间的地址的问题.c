#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
char* GetMemory(void)
{
	char p[] = "hello world";
	return p;     
}                            //出函数后，p销毁
void Test(void)
{
	char* str = NULL;
	str = GetMemory();
	printf(str);
}
int main()
{
	Test();
	return 0;
}