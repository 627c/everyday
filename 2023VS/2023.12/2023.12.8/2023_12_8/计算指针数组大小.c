#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	//һά����
	int a[] = { 1,2,3,4 };
	printf("%d\n", sizeof(a));//���������ܴ�С��16�ֽ�
	printf("%d\n", sizeof(a + 0));//4/8������������Ԫ�ص�ַ�����������������ָ���С��4/8
	printf("%d\n", sizeof(*a));//4������Ԫ����ռ�ռ��С
	printf("%d\n", sizeof(a + 1));//4/8���ڶ���Ԫ�ص�ַ
	printf("%d\n", sizeof(a[1]));//4���ڶ���Ԫ�ش�С
	printf("%d\n", sizeof(& a));//4/8��&aȡ�����������ַ����ַ��Ϊ4/8
	printf("%d\n", sizeof((*&a)));//16�����൱�ڵ�һ��
	printf("%d\n", sizeof(&a + 1));//4/8
	printf("%d\n", sizeof(&a[0]));//4/8
	printf("%d\n", sizeof(&a[0] + 1));//4/8
	return 0;
}