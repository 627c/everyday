#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	char a = -1;
	//-1 ������ȫ1
	//11111111 8������λ����8λ
	signed char b = -1;
	//11111111 8������λ
	unsigned char c = -1;
	//11111111
	printf("a=%d,b=%d,c=%d", a, b, c);   //�������� �з�����ǰ�油����λ���޷�����ǰ�油0���Բ�����в���
	return 0;
}