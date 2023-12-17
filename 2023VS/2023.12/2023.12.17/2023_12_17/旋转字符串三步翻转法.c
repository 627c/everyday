#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
void reverse(char* left, char* right)
{
	assert(left);
	assert(right);
	while (left<right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void left_move(char* arr, int k)
{
	assert(arr);
	int len = strlen(arr);
	assert(k < len);
	reverse(arr,arr+k-1);//ÄæÐò×ó±ß
	reverse(arr+k,arr+len-1);//ÄæÐòÓÒ±ß
	reverse(arr,arr+len-1);//ÄæÐòÕûÌå
}
int main()
{
	//abcdef
	//ab cdef
	//ba fedc
	//×Ö·û´®ÕûÌåÄæÐòcdefab
	char arr[] = "abcdef";
	left_move(arr, 2);
	printf("%s\n", arr);
	return 0;
}