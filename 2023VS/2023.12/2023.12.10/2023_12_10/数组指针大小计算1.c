#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	//二维数组
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));//48，3*4*4
	printf("%d\n", sizeof(a[0][0]));//4
	printf("%d\n", sizeof(a[0]));//16
	printf("%d\n", sizeof(a[0] + 1));//4/8，a[0]为第一行第一个元素地址，a[0]+1代表第一行第二个元素地址
	printf("%d\n", sizeof(*(a[0] + 1)));//4
	printf("%d\n", sizeof(a + 1));//4/8，第二行数组地址
	printf("%d\n", sizeof(*(a + 1)));//16，第二行的大小
	printf("%d\n", sizeof(&a[0] + 1));//4/8，第二行地址
	printf("%d\n", sizeof(*(&a[0] + 1)));//16，计算第二行大小
	printf("%d\n", sizeof(*a));//a是首元素地址，第一行大小，16
	printf("%d\n", sizeof(a[3]));//不会报错，sizeof实际不会访问，不会实际进行计算，故为16
	return 0;
}