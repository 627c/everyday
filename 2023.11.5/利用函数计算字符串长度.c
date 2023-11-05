#include<stdio.h>
#include<string.h>
int my_strlen(char* str)
{
	int count=0;
	while(*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
int main()
{
	char arr[]="jiangnan";
	int len = my_strlen(arr);      //数组传参传的是首元素地址
	printf("len = %d\n",len);
}