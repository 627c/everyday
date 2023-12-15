#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void encrypt(char* p)
{
	for (; *p != '\0'; p++)
	{
		if ((*p >= 'a') && (*p <= 'w'))
		{
			*p = *p + 3;
			continue;
		}
		switch (*p - 'x')
		{
		case 0:*p = 'a'; break;
		case 1:*p = 'b'; break;
		case 2:*p = 'c'; break;
		}
	}
}
void decrypt(char* p)
{
	for (; *p != '\0'; p++)
	{
		if ((*p >= 'd') && (*p <= 'z'))
		{
			*p = *p - 3;
			continue;
		}
		switch (*p - 'a')
		{
		case 0:*p = 'x'; break;
		case 1:*p = 'y'; break;
		case 2:*p = 'z'; break;
		}
	}
}
int main()
{
	char str[20];
	gets(str);
	encrypt(str);
	printf("加密后的字符串：\n");
	puts(str);
	decrypt(str);
	printf("解密后的字符串：\n");
	puts(str);
	return 0;
}