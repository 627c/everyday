#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void Print(int n)
{
	int i = 0;
	printf("����λ��\n");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (n >> i) & 1);
	}
	printf("\n");
	printf("ż��λ��\n");
	for (i = 31; i >= 1; i -= 2)
	{
		printf("%d ", (n >> i) & 1);
	}
	printf("\n");
}
int main()
{
	int a = 0;
	scanf("%d", &a);  //������Ϊ32λ
	Print(a);
	return 0;
}