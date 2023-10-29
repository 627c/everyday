#include<stdio.h>
int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	int sz=sizeof(arr)/sizeof(arr[0]);
    int left=0;
	int right=sz-1;
	int k=7;
	while(left<=right)
	{
		int mid=(left+right)/2;
		if(arr[mid]>k)
		{
			right=mid-1;
		}
		else if(arr[mid]<k)
		{
			left=mid+1;
		}
		else
		{
			printf("找到了，下标是：%d\n",mid);
			break;
		}
	}
	if(left>right) printf("找不到了\n");
}
//{
//	int arr[]={1,2,3,4,5,6,7,8,9,10};
//	int k=7;
//	int sz=sizeof(arr)/sizeof(arr[0]);
//	int i=0;
//	for(i=0;i<sz;i++)
//	{
//		if(k==arr[i])
//		{
//			printf("找到了，下标是：%d\n",i);            方法较为麻烦
//			break;
//		}
//	}
//	if(i==sz) printf("找不到\n");
//}