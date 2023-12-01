#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void change(int arr[])
{
	int i = 0;
	int m = 0, max = arr[0];
	for (i = 0; i < 10; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			m = i;
		}
	}
	int n = 0, min = arr[0];
	for(i=0;i<10;i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
			n = i;
		}
	}
	arr[m] = min;
	arr[n] = max;
}
int main()
{
	int a[10];
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}
	change(a);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}