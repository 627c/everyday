#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a[4] = { 1,2,3,4 };
	int* ptr1 = (int*)(&a + 1);
	int* ptr2 = (int*)((int)a + 1);
	printf("%x,%x", ptr1[-1], *ptr2);//ptr1[-1]==*(ptr1+(-1))==*(ptr1-1)==4
	return 0;//%x，无符号整数以16进制形式输出
}//大端，小端存储