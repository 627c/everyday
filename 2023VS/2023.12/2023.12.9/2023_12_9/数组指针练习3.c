#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	char *p = "abcdef";
	printf("%d\n", sizeof(p));//4/8,p�д洢a�ĵ�ַ
	printf("%d\n", sizeof(p+1));//4/8����b�ĵ�ַ
	printf("%d\n", sizeof(*p));//��Ԫ����ռ�ռ��С��1
	printf("%d\n", sizeof(p[0]));//1��p[0]==*(p+0),p,��Ԫ�ص�ַ���൱��arr
	printf("%d\n", sizeof(&p));//4/8
	printf("%d\n", sizeof(&p + 1));//4/8
	printf("%d\n", sizeof(&p[0] + 1));//4/8
	return 0;
}