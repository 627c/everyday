#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int i = 0;
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	for (i = 0; i <= 12; i++)
	{
		arr[i] = 0;              //arr[10],[11],[12]非法访问
		printf("hehe\n");        //死循环
	}
	return 0;
}