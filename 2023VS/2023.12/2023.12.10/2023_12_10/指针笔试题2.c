#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct Test
{
	int Num;
	char* pcNum;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;//����һ���ṹ��ָ�����p
//����p��ֵΪ0x100000.���±��ʽ��ֵ�ֱ��Ƕ��٣�
//��֪���ṹ��Test���͵ı�����С��20���ֽ�
int main()
{
	p = (struct Test*)0x100000;
	printf("%p\n", p + 0x1);//����һ���ṹ�壬20���ֽڣ�0x100000+20=0x100014
	printf("%p\n", (unsigned long)p + 0x1);//����+1��ǿ������ת��
	printf("%p\n", (unsigned int*)p + 0x1);//ǿ��ת��Ϊ�޷�������ָ�룬+1����4���ֽ�
	return 0;
}