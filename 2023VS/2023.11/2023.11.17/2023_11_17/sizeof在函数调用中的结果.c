#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void test1(int arr[])     //����������������׵�ַ������Ϊָ�룬��ռ�õĿռ���ָ����ռ�ռ䣬32λ�����Ϊ4��64λΪ8�ֽ�
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