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
	//���Ͼ�����һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ�
	//��д�����ڴ˾����в���ĳ�������Ƿ����
	//Ҫ��ʱ�临�Ӷ�С��o(N),���Բ��ܱ��������Զ��ֲ���
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int k = 7;
	int ret = FindNum(arr, k, 3, 3);
	if (ret == 1)
	{
		printf("�ҵ���\n");
	}
	else
	{
		printf("�Ҳ���\n");
	}
	return 0;
}