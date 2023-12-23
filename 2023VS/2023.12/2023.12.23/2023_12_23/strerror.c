#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<errno.h>
int main()
{
	//0.1.2.....叫做错误码，每个错误码对应一个错误信息
	// errno,是一个全局的错误码的变量
	// 当C语言的库函数在执行过程中，发生了错误，就会把对应的错误码，复制带errno中
	//0-No error
	char* str = strerror(errno);
	printf("%s\n", str);
	char* str1 = strerror(0);
	printf("%s\n", str1);
	//1-Operation not permitted
	char* str2 = strerror(1);
	printf("%s\n", str2);
	//2-No such file or directory
	char* str3 = strerror(2);
	printf("%s\n", str3);
	return 0;
}