#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void Print(int n)
{
	int i = 0;
	printf("奇数位：\n");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (n >> i) & 1);
	}
	printf("\n");
	printf("偶数位：\n");
	for (i = 31; i >= 1; i -= 2)
	{
		printf("%d ", (n >> i) & 1);
	}
	printf("\n");
}
int main()
{
	int a = 0;
	scanf("%d", &a);  //二进制为32位
	Print(a);
	return 0;
}