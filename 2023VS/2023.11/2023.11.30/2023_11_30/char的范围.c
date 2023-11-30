#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = -1 - i;     //char·¶Î§Îª-128--127
	}                      //-1,-2,....-128,127,126......,0,-1,....  0Îª½áÊø·û
	printf("%d", strlen(a));
	return 0;
}