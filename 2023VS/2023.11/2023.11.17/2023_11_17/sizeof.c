#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	short s = 0;     //�����Ϳռ�ռ2���ֽ�
	int a = 10;
	printf("%d\n", sizeof(s = a + 5));    //2 
	printf("%d\n", s);     //0  sizeof�ڲ�������������
}