#include<stdio.h>
int main()
{
	int arr[]={1,2,3,4,5,1,2,3,4}; 
	int i=0;
	int ret=0;
	int sz=sizeof(arr)/sizeof(arr[0]);        //计算数组的个数
	for(i=0;i<sz;i++)
	{
		ret=ret^arr[i];
	}
	printf("找到了，单身狗是%d\n",ret);
}