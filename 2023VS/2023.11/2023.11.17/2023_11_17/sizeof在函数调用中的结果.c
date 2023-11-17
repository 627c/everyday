#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void test1(int arr[])     //传进来的是数组的首地址，变量为指针，所占用的空间是指针所占空间，32位计算机为4，64位为8字节
{
	printf("%d\n", sizeof(arr));
}
void test2(char ch[])
{
	printf("%d\n", sizeof(ch));
}
int main()
{
	int arr[10] = { 0 };
	char ch[10] = { 0 };
	printf("%d\n", sizeof(arr));
	printf("%d\n", sizeof(ch));
	test1(arr);   //8
	test1(ch);    //8
}