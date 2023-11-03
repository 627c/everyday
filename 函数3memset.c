#include<stdio.h>
#include<string.h>
int main()
{
	char arr[]="hello world";
	memset(arr,'*',5);      //不需要赋值
	printf(arr);
}