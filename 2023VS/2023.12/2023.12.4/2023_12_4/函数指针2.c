#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void Print(char* str)
{
	printf("%s\n", str);
}
int main()
{
	void (*p)(char*) = Print;
	(*p)("hello jiangnan");
	return 0;
}