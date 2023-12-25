#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct S1
{
	char c1;
	int a;
	char c2;
};
struct S2
{
	char c1;
	char c2;
	int a;
};
int main()
{
	struct S1 s1 = { 0 };
	printf("%d\n", sizeof(s1)); //12
	struct S2 s2 = { 0 };
	printf("%d\n", sizeof(s2)); //8
	return 0;
}