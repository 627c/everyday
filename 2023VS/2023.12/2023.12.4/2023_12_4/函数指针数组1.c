#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int Add(int x, int y)
{
	return (x + y);
}
int Sub(int x, int y)
{
	return (x - y);
}
int Mul(int x, int y)
{
	return (x * y);
}
int Div(int x, int y)
{
	return (x / y);
}
int main()
{
	//int (*pa)(int, int) = Add;
	//printf("%d\n", (*pa)(2, 3));
	//��Ҫһ�����飬���������Դ���ĸ������ĵ�ַ-����ָ������
	int(*parr[4])(int, int) = { Add,Sub,Mul,Div };
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		printf("%d\n", parr[i](2, 3));
	}
	return 0;
}