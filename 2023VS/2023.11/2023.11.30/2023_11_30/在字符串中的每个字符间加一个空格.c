#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define MAX 80
void Insert(char s[]);
int main()
{
	char string[2 * MAX];
	scanf("%s", string);
	Insert(string);
	printf("%s\n", string);
	return 0;
}
void Insert(char srcStr[])
{
	char strTemp[MAX]; int i = 0, j = 0;
	strcpy(strTemp, srcStr);
	while (i < 2 * MAX)
	{
		srcStr[i++] = strTemp[j];
		j++;
		srcStr[i++] = ' ';
	}
	srcStr[i] = '\0';
}