#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		return 0;
	}
	//1.��λ�ļ�ָ��
	//SEEK_CUR �ļ���ǰλ��
	//SEEK_END �ļ���ĩβλ��
	//SEEK_SET �ļ�����ʼλ��
	fseek(pf, -2, SEEK_END);
	//2.��ȡ�ļ�
	int ch = fgetc(pf);
	printf("%c\n", ch);
	return 0;
}