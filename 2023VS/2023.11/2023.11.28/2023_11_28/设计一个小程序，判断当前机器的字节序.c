#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	//дһ�δ���������ǵ�ǰ�������ֽ�����ʲô����˴洢��С�˴洢
	int a = 20;
	//0x 00 00 00 14
	//��� 00 00 00 14
	//С�� 14 00 00 00
	char* pa = &a; //a���׵�ַ��ȡ��һ���ֽڵ�����
	if (*pa == 20)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
	return 0;
}