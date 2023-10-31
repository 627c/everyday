#include<stdio.h>
int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	int sz=sizeof(arr)/sizeof(arr[0]);
//	int max=0;     //存在问题，若为负数，则最大值为0，
	int max=arr[0];
	int i;
	for(i=0;i<sz;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	printf("max=%d",max);
}