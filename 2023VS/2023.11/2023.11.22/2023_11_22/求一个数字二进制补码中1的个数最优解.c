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
	//写一个函数表示a的二进制补码中有几个1
	int count = count_bit_one(a);   //该算法十分高效
	printf("%d\n", count);
	return 0;
}