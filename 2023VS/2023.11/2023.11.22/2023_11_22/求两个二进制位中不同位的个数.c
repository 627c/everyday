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
int get_diff_bit(int a, int b)
{
	int count = 0;
	int tmp = a ^ b;
	count = count_bit_one(tmp);  //��������
	return count;
}
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);
	//�ȶ��������ֽ��������ͬΪ0������Ϊ1���õ��Ķ���������ͳ��1�ĸ���
	int count = get_diff_bit(a, b);
	printf("%d\n", count);
	return 0;
}