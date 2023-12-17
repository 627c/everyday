#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
void reverse(char* left, char* right)
{
	assert(left);
	assert(right);
	while (left < right)
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
	reverse(arr, arr + k - 1);//ÄæÐò×ó±ß
	reverse(arr + k, arr + len - 1);//ÄæÐòÓÒ±ß
	reverse(arr, arr + len - 1);//ÄæÐòÕûÌå
}
int is_left_move(char* s1, char* s2)
{
	int len = strlen(s1);//Ðý×ªµÄ¿ÉÄÜÐÔ£¬0£¬1.¡£¡£¡££¬5
	int i = 0;
	for (i = 0; i < len; i++)
	{
		left_move(s1, 1);
		int ret = strcmp(s1, s2);
		if (ret == 0)
			return 1;
	}
	return 0;
}
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "cdefa";
	int ret = is_left_move(arr1, arr2);
	if (ret == 1)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}