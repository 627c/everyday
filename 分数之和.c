#include<stdio.h>
int main()
{
	int i;
	double sum=0;
	int flag=1;
	for(i=1;i<=100;i++)
	{
		sum+=flag*1.0/i;
		flag=-flag;
	}
	printf("%lf",sum);
}