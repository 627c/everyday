#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
void left_move(char arr[], int k)
{
	assert(arr);//���ԣ�arr��Ϊ��ָ��
	int i = 0;
	int len = strlen(arr);
	for (i = 0; i < k; i++)
	{
		//����һ���ַ�
		//step 1
		char tmp = *arr;
		//step 2
		int j = 0;
		for (j = 0; j < len-1; j++)
		{
			*(arr + j) = *(arr + j + 1);
		}
		//step 3
		*(arr + len - 1) = tmp;
	}
}
int main()
{
	//ʵ��һ�����������������ַ���k���ַ���
	//ABCD����һ���ַ��õ�BCDA
	//ABCD���������ַ��õ�CDAB
	char arr[] = "abcdef";
	left_move(arr, 2);
	printf("%s\n", arr);
	return 0;
}