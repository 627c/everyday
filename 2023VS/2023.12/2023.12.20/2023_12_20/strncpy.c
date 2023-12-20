#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	char arr1[10] = "abcdef";
	char arr2[] = "hello world";
	strncpy(arr1, arr2, 4);
	printf("%s\n", arr1);
	return 0;
}