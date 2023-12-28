#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct S
{
	int a : 2;//2个比特位
	int b : 5;
	int c : 10;
	int d : 30;
};
//47个比特位--6个字节--48个bit
//空间浪费4个字节给17，浪费15，重新开辟4个字节
int main()
{
	struct S s;
	printf("%d\n", sizeof(s)); //8个字节
	return 0;
}