#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a[5] = { 1,2,3,4,5 };
	int* ptr = (int*)(&a + 1);//强制类型转换，数组指针转换为整形指针
	printf("%d,%d\n", *(a + 1), *(ptr - 1));//2,5
	return 0;
}