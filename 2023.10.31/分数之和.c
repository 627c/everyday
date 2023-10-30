#include<stdio.h>
int main()
{
	float t,s=0;
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		t=1.0/i;
		s=s+t;
	}
	printf("s=%f\n",s);
}