#include<stdio.h>
int main()
{
	int i,n,s=1;
	printf("please enter n:");
	scanf("%d",&n);
	for(i=1;i<=n;i++) s=s*i;
	printf("%d!=%d\n",n,s);
}