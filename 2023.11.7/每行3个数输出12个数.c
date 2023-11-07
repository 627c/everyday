#include<stdio.h>
int main()
{
	int a[12];
	int i,n=12;
	float av=0;
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
		if((i+1)%3==0)  printf("\n");
	}
	for(i=0;i!=n;i++)  av+=a[i];
	av=1.0*av/n;
	printf("%f",av);
}