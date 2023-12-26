#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct S3
{
	double d;
	char c;
	int i;
};
struct S4
{
	char c1;
	struct S3 s3;
	double d;
};
int main()
{
	struct S4 s4;
	printf("%d\n", sizeof(s4));
	return 0;
}