#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
char* my_strcpy(char* dest, const char* src)      //ʹ�������г�����
{
	char* ret = dest;
	assert(dest != NULL);      //����
	assert(src != NULL);       //����
	//��srcָ����ַ���������destָ��Ŀռ䣬����'\0'zf
	while (*dest++ = *src++)        //const��ֹд����src=dest
	{
		;
	}
	return ret;
}
int main()
{
	//strcpy  �ַ�������
	char arr1[] = "###############";
	char arr2[] = "jiangnan";
	printf("%s\n", my_strcpy(arr1, arr2));    //��ʽ����
	return 0;
}