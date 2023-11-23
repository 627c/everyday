#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int i = 0,j=0,p,q,s;
	int a[11] = { 0 };
	int x = 0;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < 10; i++)
	{
		p = i; q = a[i];
		for(j=i+1;j<10;j++)
			if (q < a[j])
			{
				p = j;
				q = a[j];
			}
		if (i != p)
		{
			s = a[i];
			a[i] = a[p];
			a[p] = s;
		}
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("请输入要插入的数：\n");
	scanf("%d", &x);
	for (i = 0; i < 10; i++)
	{
		if (x < a[i])
			continue;
		for (j = 10; j>i; j--)
		{
			a[j] = a[j - 1];
		}
		a[i] = x;
		break;
	}
	for (i = 0; i < 11; i++)
		printf("%d ", a[i]);
}