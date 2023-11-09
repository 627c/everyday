#include<stdio.h>
void bubble_sort(int arr[],int sz)
{
	//确定冒泡排序趟数，n个元素是n-1趟
	int i;
	int j;
//	int sz=sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<sz-1;i++)
	{
		int flag=1;          //假设已经有序
		//每一趟冒泡排序
		for(j=0;j<sz-1-i;j++)
		{
			if(arr[j]>arr[j+1])     //升序排列
			{
				int tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
				flag=0;         //本趟数据不完全有序
			}
		}
		if(flag==1)
		{
			break;           //优化
		}
	}
}
int main()
{
	int arr[] = {0,8,7,6,5,4,3,2,1};
	//对arr进行排序，排成升序
	int i;
	int sz=sizeof(arr)/sizeof(arr[0]);
	//arr是数组，对数组进行传参，传的并不是数组本身，而是数组首元素地址
	bubble_sort(arr,sz);    //冒泡排序函数
	for(i=0;i<sz;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}