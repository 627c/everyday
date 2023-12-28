#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct S
{
	char a : 3;
	char b : 4;
	char c : 5;
	char d : 4;
};
//3¸ö×Ö½Ú*8¸öbit
int main()
{
	struct S s = { 0 };
	s.a = 10;
	s.b = 20;
	s.c = 3;
	s.d = 4;
	printf("%d\n", sizeof(s));
	return 0;
}