#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct S
{
	char c;
	int a;
	double d;
	char arr[20];
};
int main()
{
	struct S s = { 'c',100,3.14,"hello" };
	printf("%c %d %lf %s\n", s.c, s.a, s.d, s.arr);
	return 0;
}