#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void test(void)
{
	char* str = (char*)malloc(100);
	strcpy(str, "hello");
	free(str);      //free释放str指向的空间后，并不会把str置为NULL
	if (str != NULL)
	{
		strcpy(str, "world");     //出现很大问题，非法访问内存
		printf(str);
	}
}
int main()
{
	test();
	return 0;
}