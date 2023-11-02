#include<stdio.h>
int main()
{
	float sum=0.0,j=1.0;
	int i;
	for(i=1;i<20;i++)
	{
		j*=i;
		if(i%2==0)  continue;
		sum+=j;
	}
	printf("sum=%e\n",sum);
}