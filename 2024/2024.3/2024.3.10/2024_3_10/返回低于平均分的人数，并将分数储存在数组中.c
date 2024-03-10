#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int fun(int score[], int m, int below[])
{
	int i = 0;
	int j = 0;
	int aver = 0;
	int count = 0;
	for (i = 0; i < m; i++)
	{
		aver += score[i] / m;
	}
	for (i = 0; i < m; i++)
	{
		if (score[i] < aver)
		{
			count++;
			below[j++] = score[i];
		}
	}
	return count;
}
int main()
{
	int score[] = { 10,20,30,40,50,60,70,80,90 };
	int m = sizeof(score) / sizeof(score[0]);
	int below[10];
	int count = fun(score, m, below);
	printf("%d\n", count);
	int i = 0;
	for (i = 0; i<count ; i++)
	{
		printf("%d ", below[i]);
	}
	return 0;
}