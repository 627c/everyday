#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int my_strlen(char* str)
{
	char* start = str;
	char* end = str;
	while (*end != '\0')
	{
		end++;
	}
	return end - start;
}
int main()
{
	//strlen-���ַ�������
	//�ݹ�-ģ��ʵ����strlen-�������ķ�ʽ1���ݹ�ķ�ʽ2
	char arr[] = "jiangnan";
	int len = my_strlen(arr);
	printf("%d\n", len);
}