#include<stdio.h>
int main()
{
	//交换两个变量值，但不引入第三个变量
	int a=3;
	int b=5;
	printf("a=%d,b=%d\n",a,b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("a=%d,b=%d\n",a,b);
}
//代码存在算法存在问题，溢出的问题，若a和b过大，则会造成溢出问题