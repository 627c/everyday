#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	char arr[10] = "";
	memset(arr, '#', 10);//10���ֽ�
	puts(arr);
	return 0;
}