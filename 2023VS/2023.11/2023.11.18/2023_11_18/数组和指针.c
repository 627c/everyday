#include<stdio.h>
int main()
{
	int arr[10] = { 0 };
	int* p = arr;  //数组名-首元素地址
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		*(p + i) = 1;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d", arr[i]);
	}
}