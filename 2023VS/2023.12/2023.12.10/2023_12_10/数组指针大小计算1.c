#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	//��ά����
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));//48��3*4*4
	printf("%d\n", sizeof(a[0][0]));//4
	printf("%d\n", sizeof(a[0]));//16
	printf("%d\n", sizeof(a[0] + 1));//4/8��a[0]Ϊ��һ�е�һ��Ԫ�ص�ַ��a[0]+1�����һ�еڶ���Ԫ�ص�ַ
	printf("%d\n", sizeof(*(a[0] + 1)));//4
	printf("%d\n", sizeof(a + 1));//4/8���ڶ��������ַ
	printf("%d\n", sizeof(*(a + 1)));//16���ڶ��еĴ�С
	printf("%d\n", sizeof(&a[0] + 1));//4/8���ڶ��е�ַ
	printf("%d\n", sizeof(*(&a[0] + 1)));//16������ڶ��д�С
	printf("%d\n", sizeof(*a));//a����Ԫ�ص�ַ����һ�д�С��16
	printf("%d\n", sizeof(a[3]));//���ᱨ��sizeofʵ�ʲ�����ʣ�����ʵ�ʽ��м��㣬��Ϊ16
	return 0;
}