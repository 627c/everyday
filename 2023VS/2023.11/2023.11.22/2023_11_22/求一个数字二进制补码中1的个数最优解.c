#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int count_bit_one(int n)
{
	int count = 0;
	while (n)
	{
		n = n & (n - 1);
		count++;
	}
	return count;
}
int main()
{
	int a = 0;
	scanf("%d", &a);
	//дһ��������ʾa�Ķ����Ʋ������м���1
	int count = count_bit_one(a);   //���㷨ʮ�ָ�Ч
	printf("%d\n", count);
	return 0;
}