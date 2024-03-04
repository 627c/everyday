#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int fun(char a[50])
{
	int s = strlen(a);
	int i, j;
	for (i = 0, j = s - 1; i < s, j >= 0; i++, j--)
	{
		if (a[i] == a[j])
		{
			continue;
		}
		break;
	}
	if (j <= i)
	{
		return 1;
	}
	return 0;
}
int main()
{
	char a[50];
	scanf("%s", a);
	int re = fun(a);
	if (re == 1)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
	return 0;
}