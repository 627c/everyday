#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	char arr[] = "abcdef";
	printf("%d\n", sizeof(arr));//���������Ĵ�С��7
	printf("%d\n", sizeof(arr + 0));//��Ԫ�ص�ַ��ָ���С��4/8
	printf("%d\n", sizeof(*arr));//��Ԫ����ռ�ռ��С��1
	printf("%d\n", sizeof(arr[1]));//1
	printf("%d\n", sizeof(&arr));//4/8
	printf("%d\n", sizeof(&arr + 1));//4/8
	printf("%d\n", sizeof(&arr[0] + 1));//4/8
	return 0;
}