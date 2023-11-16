#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 10
int main()
{
	int a[] = { 0,1,2,3,4,5,6,7,8,9 }, k;
	int low = 0, high = N - 1, mid, find = 0;
	printf("输入要查找的值：\n");
	scanf("%d", &k);
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (a[mid] == k)
		{
			printf("找到位置为：%d\n", mid + 1); find = 1;
		}
		if (a[mid] > k)
			high = mid - 1;
		else
			low = mid + 1;
	}
	if (!find)
		printf("%d未找到\n", k);
}