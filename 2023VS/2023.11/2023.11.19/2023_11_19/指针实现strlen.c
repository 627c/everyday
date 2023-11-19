#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int my_strlen(char* str)
{
	char* start = str;
	char* end = str;
	while (*end != '\0')
	{
		end++;
	}
	return end - start;
}
int main()
{
	//strlen-求字符串长度
	//递归-模拟实现了strlen-计数器的方式1，递归的方式2
	char arr[] = "jiangnan";
	int len = my_strlen(arr);
	printf("%d\n", len);
}