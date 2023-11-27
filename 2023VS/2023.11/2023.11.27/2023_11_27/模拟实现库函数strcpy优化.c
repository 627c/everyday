#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void my_strcpy(char* dest, char* src)
{
	while (*dest++ = *src++)
	{
		;
	}
}
int main()
{
	//strcpy  ×Ö·û´®¿½±´
	char arr1[] = "###############";
	char arr2[] = "jiangnan";
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}