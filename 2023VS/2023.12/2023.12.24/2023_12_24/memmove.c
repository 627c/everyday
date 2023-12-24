#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	//C语言标准规定
	//memcpy只要处理不重叠的内存拷贝就可以
	//memmove 可以处理不重叠，也可以处理重叠内存的拷贝
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	//memcpy(arr + 2, arr, 20); //1 2 1 2 3 4 5 8 9 10
	memmove(arr + 2, arr, 20);  //1 2 1 2 3 4 5 8 9 10
	//memmove 解决重叠拷贝问题
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	return 0;
}