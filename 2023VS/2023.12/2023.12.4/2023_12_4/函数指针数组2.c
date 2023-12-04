#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	char* my_strcpy(char* dest, const char* src);
	//函数指针
	//char** pf = my_strcpy;
	char* (*pf)(char*, const char*) = my_strcpy;
	//函数指针数组
	char* (*pfArr[4])(char*, const char*) = { my_strcpy,my_strcpy,my_strcpy,my_strcpy};
	return 0;
}