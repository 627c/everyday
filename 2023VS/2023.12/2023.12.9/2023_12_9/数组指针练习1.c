#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	char arr[] = "abcdef";
	printf("%d\n", sizeof(arr));//计算得数组的大小，7
	printf("%d\n", sizeof(arr + 0));//首元素地址即指针大小，4/8
	printf("%d\n", sizeof(*arr));//首元素所占空间大小，1
	printf("%d\n", sizeof(arr[1]));//1
	printf("%d\n", sizeof(&arr));//4/8
	printf("%d\n", sizeof(&arr + 1));//4/8
	printf("%d\n", sizeof(&arr[0] + 1));//4/8
	return 0;
}