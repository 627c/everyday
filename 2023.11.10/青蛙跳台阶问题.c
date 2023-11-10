#include<stdio.h>
int dance_step(int n)
{
	if(n==1)
		return 1;   //当只有一层台阶时
	if(n==2)
		return 2;   //当有两层台阶时
	if(n>2)
		return dance_step(n-1)+dance_step(n-2);       //类似斐波那契函数，构成递归
}
int main()
{
	int n=0;
	scanf("%d",&n);
	int num=dance_step(n);
	printf("%d\n",num);
}