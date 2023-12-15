#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	char str[20];
	gets(str);
	char* pstr = str;
	int count = 0;
	int a[20] = { 0 };
	int num = 0;
	int i, j;
	for (; *pstr != '\0'; pstr++)
	{
		if ((*pstr >= '0') && (*pstr <= '9'))
		{
			a[count] = *pstr - 48;
			count++;
		}
	}
	for (i = count - 1, j = 0; i >= 0, j < count; i--, j++)
	{
		num += a[i] * pow(10, j);
	}
	printf("%d\n", num);
	return 0;
}