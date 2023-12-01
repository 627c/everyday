#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void bin(int n)
{
	int i=0,j,num[20];
	do {
		i++;
		num[i] = n % 2;
		n = n / 2;
	} while (n);
	for (j = i; j >= 1; j--)
		printf("%d", num[j]);
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("二进制形式为:");
	bin(n);
	return 0;
}