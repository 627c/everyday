#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int pal(char arr[])
{
	int sz = strlen(arr);
	int i = 0,j=0;
	for (i = 0,j=sz-1;i<=j; i++,j--)
	{
		if (arr[i] == arr[j]) continue;
		break;
	}
	if (i >= j) return 1;
	else return 0;
}
int main()
{
	char a[10], b[10], c[10], d[10], e[10];
	gets(a);
	gets(b);
	gets(c);
	gets(d);
	gets(e);
	int reta, retb, retc, retd, rete;
	reta = pal(a);
	retb = pal(b);
	retc = pal(c);
	retd = pal(d);
	rete = pal(e);
	int count = reta + retb + retc + retd + rete;
	printf("%d\n", count);
	return 0;
}