#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	char ch[20] = { 0 };
	printf("ÇëÊäÈë×Ö·û´®£º\n");
	gets(ch);
	int sz = strlen(ch);
	int i = 0, j = 0;
	printf("ÇëÊäÈëÒªÉ¾³ıµÄ×Ö·û£º\n");
	char opt = getchar();
	for (i = 0; i < sz; i++)
	{
		if (ch[i] == opt)
		{
			for (j = i; j < sz; j++)
			{
				ch[j] = ch[j + 1];
			}
		}
	}
	puts(ch);
	return 0;
}