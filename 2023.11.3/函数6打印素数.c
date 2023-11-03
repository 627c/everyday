#include<stdio.h>
int is_prime(int n)       //是素数返回1，不是返回0
{
	int m;
//	int count=0;
	for(m=2;m<n;m++)     //优化，n可以替换为sqrt（n），要用<=
	{
		if(n%m==0)
			return 0;    //只要执行则整个函数结束
//			count+=1;
	}
	return 1;
//	if(count==0)
//		return 1;
//	else
//		return 0;
}
int main()
{
	int i=0;
	for(i=100;i<=200;i++)
	{
		if(is_prime(i)==1)
			printf("%d ",i);
	}
}