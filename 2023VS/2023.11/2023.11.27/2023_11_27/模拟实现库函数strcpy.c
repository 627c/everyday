#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void my_strcpy(char* dest, char* src)
{
	while(*src!='\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = *src;     //\0�Ŀ���
}
int main()
{
	//strcpy  �ַ�������
	char arr1[] = "###############";
	char arr2[] = "jiangnan";
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}