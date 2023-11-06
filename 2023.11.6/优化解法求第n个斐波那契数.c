#include<stdio.h>
int fib(int n)
{
	int a=1;
	int b=1;
	int c=1;
	while(n>2)
	{
		c=a+b;
		a=b;
		b=c;
		n--;
	}
	return c;
}
int main()                          //速度十分快
{
	int n;
	int ret;
	scanf("%d",&n);
	ret = fib(n);
	printf("第%d个斐波那契数为：%d",n,ret);
}