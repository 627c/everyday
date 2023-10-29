#include<stdio.h>
int main()
{
	int i=0;
	int p;
	long int q=1;
	long int sum=0;
	for(i=1;i<=10;i++)
	{
		for(p=1;p<=i;p++)
		{
			q=q*p;
		}
		sum+=q;
	}
	printf("%d\n",sum);
}