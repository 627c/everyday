#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	//一维数组
	int a[] = { 1,2,3,4 };
	printf("%d\n", sizeof(a));//计算数组总大小，16字节
	printf("%d\n", sizeof(a + 0));//4/8，数组名是首元素地址，非两种特殊情况，指针大小，4/8
	printf("%d\n", sizeof(*a));//4，求首元素所占空间大小
	printf("%d\n", sizeof(a + 1));//4/8，第二个元素地址
	printf("%d\n", sizeof(a[1]));//4，第二个元素大小
	printf("%d\n", sizeof(& a));//4/8，&a取出的是数组地址，地址就为4/8
	printf("%d\n", sizeof((*&a)));//16，就相当于第一个
	printf("%d\n", sizeof(&a + 1));//4/8
	printf("%d\n", sizeof(&a[0]));//4/8
	printf("%d\n", sizeof(&a[0] + 1));//4/8
	return 0;
}