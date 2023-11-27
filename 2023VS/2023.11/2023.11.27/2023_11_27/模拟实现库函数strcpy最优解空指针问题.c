#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
char* my_strcpy(char* dest, const char* src)      //使变量具有常属性
{
	char* ret = dest;
	assert(dest != NULL);      //断言
	assert(src != NULL);       //断言
	//把src指向的字符串拷贝到dest指向的空间，包含'\0'zf
	while (*dest++ = *src++)        //const防止写反，src=dest
	{
		;
	}
	return ret;
}
int main()
{
	//strcpy  字符串拷贝
	char arr1[] = "###############";
	char arr2[] = "jiangnan";
	printf("%s\n", my_strcpy(arr1, arr2));    //链式访问
	return 0;
}