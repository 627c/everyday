#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	//�ַ�����
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", strlen(arr));//���ֵ
	printf("%d\n", strlen(arr + 0));//���ֵ
	//printf("%d\n", strlen(*arr));//��a����97��Ϊ��ַ���Ƿ����ʣ��������
	//printf("%d\n", strlen(arr[1]));//��b�����Ƿ�����
	printf("%d\n", strlen(&arr));//���ֵ
	printf("%d\n", strlen(&arr + 1));//���������ֵ��6
	printf("%d\n", strlen(&arr[0] + 1));//���������ֵ��1
	return 0;
}