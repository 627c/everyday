#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int check_sys()
{
	int a = 1;
	char* pa = &a;
	return *pa;   //����1��С�ˣ�����0�����
}
int main()
{
	//����1��С��
	//����0�����
	int ret = check_sys();
	if (ret == 1)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
	return 0;
}