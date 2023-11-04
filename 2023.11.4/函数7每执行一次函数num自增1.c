#include<stdio.h>
int Add(int* p)
{
	(*p)++;     //++比*优先级高，所以要加括号
}
int main()
{
	int num=0;  
	Add(&num);    //每调用一次函数，num的值加1，可以理解为Add函数可以改变num的值，改变参数值不能直接传参，而应该传入地址
	printf("%d\n",num);
	Add(&num);
	printf("%d\n",num);
	Add(&num);
	printf("%d\n",num);
}