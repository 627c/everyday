#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int i, a[10], sum = 0, count;
	count = 0;
	for (i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < 10; i++)
	{
		if (a[i] < 0)
			continue;
		sum += a[i];
		count++;
	}
	printf("sum=%d,count=%d\n", sum, count);
}