#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	char *p = "abcdef";
	printf("%d\n", sizeof(p));//4/8,p中存储a的地址
	printf("%d\n", sizeof(p+1));//4/8，存b的地址
	printf("%d\n", sizeof(*p));//首元素所占空间大小，1
	printf("%d\n", sizeof(p[0]));//1，p[0]==*(p+0),p,首元素地址，相当于arr
	printf("%d\n", sizeof(&p));//4/8
	printf("%d\n", sizeof(&p + 1));//4/8
	printf("%d\n", sizeof(&p[0] + 1));//4/8
	return 0;
}