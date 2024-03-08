#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void fun(char a[])
{
	int i = 0;
	for (i = 0; i < strlen(a); i++)
	{
		if ((i % 2 == 1) && (a[i] >= 'a' && a[i] <= 'z'))
			a[i] = a[i] + 'A' - 'a';
	}
}
int main()
{
	char a[38] = "abc4Efg";
	fun(a);
	int i = 0;
	printf("%s\n", a);
	return 0;
}