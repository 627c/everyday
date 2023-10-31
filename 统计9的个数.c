#include<stdio.h>
int main()
{
	int i;
	int count=0;
	for(i=1;i<=100;i++)
	{
		if(i%10==9)   //个位是否为9
		{
			count++;
		}
		if(i/10==9)  //十位是否为9  ，不能用else if,因为99 有两个9
		{
			count++;
		}
	}
	printf("%d",count);
}