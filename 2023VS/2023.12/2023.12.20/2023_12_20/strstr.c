#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	char* p1 = "abcdefghi";
	char* p2 = "def";
	char* ret = strstr(p1, p2);
	if (ret == NULL)
	{
		printf("×Ó´®²»´æÔÚ\n");
	}
	else
	{
		printf("%s\n", ret);
	}
	return 0;
}