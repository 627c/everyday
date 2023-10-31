#include<stdio.h>
int main()
{
	int m=18;
	int n=24;
	int r;
	while(m%n)
	{
		r=m%n;
		m=n;
		n=r;
	}
	printf("%d",r);
}