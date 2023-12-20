#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	//strncmp-×Ö·û´®±È½Ï
	const char* p1 = "abcdef";
	char* p2 = "abcqwer";
	int ret = strncmp(p1, p2, 3);
	printf("%d\n", ret);
	return 0;
}