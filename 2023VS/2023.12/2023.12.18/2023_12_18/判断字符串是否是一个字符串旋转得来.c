#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int is_left_move(char* str1, char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2)
		return 0;
	//1.��str1�ַ�����׷��һ��str1�ַ���
	//strcat(str1, str1);�Լ����Լ�׷�Ӳ��������������error
	//strncat(str1,str1,n) n,��׷��n���ַ�
	strncat(str1, str1, 6);
	//2.�ж�str2ָ����ַ����Ƿ���str1ָ����ַ������ִ�
	//strstr-���Ӵ���
	char* ret = strstr(str1, str2);
	if (ret == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	char arr1[30] = "abcdef";
	char arr2[] = "cdefab";
	int ret = is_left_move(arr1, arr2);
	if (ret == 1)
	{
		printf("Yes\n");
	}
	else
		printf("No\n");
	return 0;
}