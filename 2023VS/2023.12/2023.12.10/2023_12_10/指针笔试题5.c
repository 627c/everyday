#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a[5][5];
	int(*p)[4];
	p = a;
	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);//p[4][2]==*(*(p+4)+2)
	return 0;
}//-4,%p打印地址不存在原反补之分，直接把-4补码拿出来当原码，按地址输出