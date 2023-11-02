#include<stdio.h>
int main()
{
	int r,m,n,k,t;
	scanf("%d%d",&m,&n);
	if(m<n)
	{
		t=m;
		m=n;
		n=t;
	}
	k=m*n;
	r=m%n;
	while(r)
	{
		m=n;
		n=r;
		r=m%n;
	}
	printf("%d %d\n",n,k/n);
}