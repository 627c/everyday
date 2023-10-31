//1*1=1
//2*1=2 2*2=4
//a*b=n  a为行，b为列
#include<stdio.h>
int main()
{
	int i;
	for(i=1;i<=9;i++)
	{
		//打印一行
		int j;
		for(j=1;j<=i;j++)
		{
			printf("%d*%d=%-2d ",i,j,i*j);  //两位左对齐
		}
		printf("\n");
	}
}