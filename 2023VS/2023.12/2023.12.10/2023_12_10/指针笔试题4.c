#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a[3][2] = { (0,1),(2,3),(4,5) };//圆括号里面是逗号表达式，表达式结果为最后一个表达式
	int* p;
	p = a[0];
	printf("%d", p[0]);
	return 0;
}