#include<stdio.h>
#include<string.h>
int main()
{
	char arr1[]="jiangnan";
	char arr2[20]="################";
	strcpy(arr2,arr1);     //字符串拷贝
	printf("%s",arr2);
}