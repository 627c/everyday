#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int check_sys()
{
	union Un
	{
		char c;
		int i;
	}u;
	u.i = 1;
	return u.c;
}
int main()
{
	//int a = 0x11223344; //���ֽ�----���ֽ�
	//�͵�ַ----------�ߵ�ַ
	//11 22 33 44   ����ֽ���洢
	//44 33 22 11   С���ֽ���洢
	//����һ�����ݣ������ڴ��е��ֽ�˳��
	//��С���ֽ�������
	int ret = check_sys();
	if (1 == ret)
	{
		printf("С���ֽ���洢\n");
	}
	else
	{
		printf("����ֽ���洢\n");
	}
	return 0;
}