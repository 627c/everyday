#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int num = 0;
	int count = 0;
	scanf("%d", &num);
	//统计num的补码中有几个1
	//while (num)         这种算法存在问题，当输入为负数时，不能正确计算
	//{
	//	if (num % 2 == 1)
	//		count++;
	//	num = num / 2;
	//}
	//按位与来做，搭配右移操作符
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if (1 == ((num >> i) & 1))
			count++;
	}
	printf("%d\n", count);
}