#include<stdio.h>
#include<string.h>
#include<windows.h>
int main()
{
	char arr1[]="welcome to jiangnan!!!";
	char arr2[]="**********************";
	int left=0;
	int right=strlen(arr1)-1;    //strlen 计算字符串长度，不加\0
	while(left<=right)
	{
		arr2[left]=arr1[left];
		arr2[right]=arr1[right];
		printf("%s\n",arr2);
		left++;
		right--;
		Sleep(1000);  //休息1000ms，即1s
	}
}