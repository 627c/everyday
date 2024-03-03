#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
char* fun(char(*a)[50], int num)
{
	char* max = a[0];
	int i = 0;
	for (i = 0; i < num; i++)
	{
		if (strlen(a[i]) > strlen(max))
		{
			max = a[i];
		}
	}
	return max;
}
int main()
{
	char a[][50] = { 0 };
	int i = 0, num;
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		gets(a[i][50]);
	}
	char* max = fun(a, num);
	printf("%s\n", max);
	return 0;
}