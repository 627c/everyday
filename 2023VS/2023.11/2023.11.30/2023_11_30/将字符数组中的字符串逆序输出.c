#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define ARR_SIZE 80
void Inverse(char str[]);
int main()
{
	char str[ARR_SIZE];
	int len;
	printf("please enter a string:");
	gets(str);
	len = strlen(str);
	Inverse(str);
	printf("the inverse string is:");
	puts(str);
	return 0;
}
void Inverse(char str[])
{
	int len,i = 0, j; char tmp;
	len = strlen(str);
	for (j = len - 1; i <= j; i++, j--)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
}