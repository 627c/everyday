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
	count = count_bit_one(tmp);  //函数调用
	return count;
}
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);
	//先对两个数字进行异或，相同为0，相异为1，得到的二进制数再统计1的个数
	int count = get_diff_bit(a, b);
	printf("%d\n", count);
	return 0;
}