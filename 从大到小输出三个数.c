#include<stdio.h>
int main()
{
	int a=0;
	int b=0;
	int c=0;
	scanf("%d%d%d",&a,&b,&c);
	if(a<b)
	{
		int tmp=a;
		a=b;
		b=tmp;
	}
 	if(a<c)
 	{
 		int tmp=c;
 		c=a;
 		a=tmp;
 	}
 	if(b<c)
 	{
 		int tmp=c;
 		c=b;
 		b=tmp;
	}
	printf("%d %d %d\n",a,b,c);
}