#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//F5�������ԣ�ͨ�����F9ʹ�ã�F9���öϵ�����л��ϵ�
//F10����̣�F11�����
int main()
{
	int i = 0;
	for (i = 0; i < 100; i++)
	{
		printf("%d ", i);
	}
	for (i = 0; i < 100; i++)
	{
		printf("%d ", 10-i);
	}
	return 0;
}