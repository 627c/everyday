#include<stdio.h>
int my_strlen(char* str)
{
	if(*str!='\0')
		return 1+my_strlen(str+1);
	else
		return 0;
}
int main()
{
	char arr[]="jiangnan";
	int len = my_strlen(arr);      //数组传参传的是首元素地址
	printf("len = %d\n",len);
}