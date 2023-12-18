#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int FindNum(int arr[3][3], int k, int row, int col)
{
	int x = 0;
	int y = col - 1;
	while(x<=row-1&&y>=0)
	{
		if (arr[x][y] > k)
		{
			y--;
		}
		else if (arr[x][y] < k)
		{
			x++;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	//杨氏矩阵，有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，
	//编写程序在此矩阵中查找某个数字是否存在
	//要求时间复杂度小于o(N),所以不能遍历，可以二分查找
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int k = 7;
	int ret = FindNum(arr, k, 3, 3);
	if (ret == 1)
	{
		printf("找到了\n");
	}
	else
	{
		printf("找不到\n");
	}
	return 0;
}