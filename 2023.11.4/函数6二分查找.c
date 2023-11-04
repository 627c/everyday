#include<stdio.h>
int binary_search(int arr[],int k,int sz)     //本质上arr是指针，后面无法再求数组元素个数，应该再传参时，把数组元素个数也传入
{
	//算法的实现
	int left=0;
//	int right=sizeof(arr)/sizeof(arr[0])-1;
	int right=sz-1;
//	int mid=(left+right)/2;   mid要放入while内
	while(left<=right)
	{
		int mid=(left+right)/2;
		if(arr[mid]<k)
		{
			left=mid+1;
		}
		else if(arr[mid]>k)
		{
			right=mid-1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	int sz=sizeof(arr)/sizeof(arr[0]);
	int k=7;
	int ret=binary_search(arr,k,sz);    //binary_search 意为二分查找
	if(ret==-1)
	{
		printf("找不到指定的数字\n");
	}
	else
	{
		printf("找到了，下标是：%d\n",ret);
	}
	return 0;
}