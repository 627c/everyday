#include<stdio.h>
int main()
{
	int a=3;   //3--011
	int b=5;   //5--101
	printf("a=%d,b=%d\n",a,b);
	a=a^b;     //110
	b=a^b;     //011
	a=a^b;     //101           //按位异或
	printf("a=%d,b=%d\n",a,b);
}