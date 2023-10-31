#include<stdio.h>
#include<math.h>
int main()
{
	int i;
	int count=0;
	for(i=101;i<=200;i+=2)      //优化
	{
		int j;
		for(j=2;j<=sqrt(i);j++)
		{
			if(i%j==0)
			{
				break;
			}
		}
		if(j>sqrt(i))
		{
			printf("%d ",i);
			count++;
		}
//		for(j=2;j<i;j++)
//		{
//			if(i%j==0)
//			{
//				break;
//			}
//		}
//		if(j==i)
//		{
//			printf("%d是素数\n",i);
//			count++;
//		}
	}
	printf("\n");
	printf("%d",count);
}