#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void Init(int arr[], int  sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = i+1;
	}
}
void Print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
void Reverse(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}
int main()
{
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Init(arr, sz);  //把数组初始化为0
	Print(arr, sz);  //打印
	printf("\n");
	Reverse(arr,sz); //逆序
	Print(arr, sz);  //打印
	return 0;
}