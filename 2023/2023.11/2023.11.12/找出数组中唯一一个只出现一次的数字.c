#include<stdio.h>
int main()
{
	int arr[]={1,2,3,4,5,1,2,3,4};              //这是一种暴力求解
	int i=0;
	int sz=sizeof(arr)/sizeof(arr[0]);        //计算数组的个数
	for(i=0;i<sz;i++)
	{
		int count=0;
		//统计arr[i]在arr数组中出现了几次
		int j=0;
		for(j=0;j<sz;j++)
		{
			if(arr[i]==arr[j])
			{
				count++;
			}
		}
		if(count==1)
		{
			printf("找到了，单身狗是%d\n",arr[i]);
			break;
		}
	}
}