#include<stdio.h>
void swap2(int* pa,int* pb)
{
	int tmp=0;
	tmp=*pa;
	*pa=*pb;
	*pb=tmp;
}
int main()

{
	int a=10;
	int b=20;
	printf("a=%d b=%d\n",a,b);
	//调用函数
	swap2(&a,&b);
	printf("a=%d b=%d\n",a,b);
//	int a=10;
//	int* pa=&a;   //取地址，pa指针变量
//	*pa=20;      //解引用操作
//	printf("%d\n",a);
}
//void swap(int x,int y)
//{
//	int tmp=0;
//	tmp=x;
//	x=y;
//	y=tmp;                                     
//}
//{
//	int a=10;                          a和b有独立空间，x和y也有独立空间，a和b的值传给了x和y，但是x和y与a和b并无关系了，所以交换后的值不能传回a和b
//	int b=20;
//	printf("a=%d b=%d\n",a,b);
//	swap(a,b);
//	printf("a=%d b=%d\n",a,b);
//}

//当实参传给形参时，形参是实参的一份临时拷贝，实参和形参之间没有实际联系，对形参的改变是不会改变实参的