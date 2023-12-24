#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[5] = { 0 };
	memcpy(arr2, arr1, sizeof(arr1));
	int i = 0;
	for (i = 0; i < 5; i++)
		printf("%d ", arr2[i]);
	return 0;
}