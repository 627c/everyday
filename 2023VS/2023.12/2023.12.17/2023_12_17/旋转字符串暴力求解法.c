#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
void left_move(char arr[], int k)
{
	assert(arr);//断言，arr不为空指针
	int i = 0;
	int len = strlen(arr);
	for (i = 0; i < k; i++)
	{
		//左旋一个字符
		//step 1
		char tmp = *arr;
		//step 2
		int j = 0;
		for (j = 0; j < len-1; j++)
		{
			*(arr + j) = *(arr + j + 1);
		}
		//step 3
		*(arr + len - 1) = tmp;
	}
}
int main()
{
	//实现一个函数，可以左旋字符串k个字符串
	//ABCD左旋一个字符得到BCDA
	//ABCD左旋两个字符得到CDAB
	char arr[] = "abcdef";
	left_move(arr, 2);
	printf("%s\n", arr);
	return 0;
}