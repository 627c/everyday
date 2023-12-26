#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct S3
{
	double d;
	char c;
	int i;
};
int main()
{
	struct S3 s3;
	printf("%d\n", sizeof(s3));
	return 0;
}