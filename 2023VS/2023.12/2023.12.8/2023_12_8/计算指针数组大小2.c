#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	//字符数组
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", strlen(arr));//随机值
	printf("%d\n", strlen(arr + 0));//随机值
	//printf("%d\n", strlen(*arr));//‘a’，97作为地址，非法访问，程序崩溃
	//printf("%d\n", strlen(arr[1]));//‘b’，非法访问
	printf("%d\n", strlen(&arr));//随机值
	printf("%d\n", strlen(&arr + 1));//与上面随机值差6
	printf("%d\n", strlen(&arr[0] + 1));//比上面随机值少1
	return 0;
}