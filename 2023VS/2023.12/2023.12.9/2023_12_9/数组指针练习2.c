#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	char arr[] = "abcdef";
	printf("%d\n", strlen(arr));//6,
	printf("%d\n", strlen(arr + 0));//6
	//printf("%d\n", strlen(*arr));//�Ƿ����ʣ����򱨴�
	//printf("%d\n", strlen(arr[1]));//����ͬ��
	printf("%d\n", strlen(&arr));//6
	printf("%d\n", strlen(&arr + 1));//���ֵ
	printf("%d\n", strlen(&arr[0] + 1));//5
	return 0;
}