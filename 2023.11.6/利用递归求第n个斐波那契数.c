#include<stdio.h>
int fib(int n)
{
	if((n==1)||(n==2))
		return 1;
	else
		return fib(n-1)+fib(n-2);
}
int main()                         //运行时间十分长，因为有很多重复计算的步骤
{
	int n;
	int ret;
	scanf("%d",&n);
	ret = fib(n);
	printf("第%d个斐波那契数为：%d",n,ret);
}