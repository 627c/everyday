#include<stdio.h>
int main()
{
	int i=0;
	int q=1;
	long int sum=0;
	for(i=1;i<=10;i++)
	{
		q=q*i;
		sum+=q;
	}
	printf("%d\n",sum);
}
//{
//	int i=0;
//	int p;
//	int q=1;
//	long int sum=0;
//	for(i=1;i<=10;i++)
//	{
//		q=1;
//		for(p=1;p<=i;p++)
//		{                            方法二，较为复杂
//			q=q*p;
//		}
//		sum+=q;
//	}
//	printf("%d\n",sum);
//}
//{
//	int i=0;
//	int p;
//	long int q=1;
//	long int sum=0;
//	for(i=1;i<=10;i++)
//	{
//		for(p=1;p<=i;p++)
//		{
//			q=q*p;      错误原因，q的值不会赋初值1，会一直保留，不会置1，应该在循环中重新设置，不能用static,具体看static用法
//		}
//		sum+=q;
//	}
//	printf("%d\n",sum);
//}
