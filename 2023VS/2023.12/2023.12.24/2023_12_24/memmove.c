#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	//C���Ա�׼�涨
	//memcpyֻҪ�����ص����ڴ濽���Ϳ���
	//memmove ���Դ����ص���Ҳ���Դ����ص��ڴ�Ŀ���
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	//memcpy(arr + 2, arr, 20); //1 2 1 2 3 4 5 8 9 10
	memmove(arr + 2, arr, 20);  //1 2 1 2 3 4 5 8 9 10
	//memmove ����ص���������
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	return 0;
}