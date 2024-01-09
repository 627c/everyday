#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a = 10000;
	FILE* pf = fopen("test.txt", "wb");//文件不存在时，先自动创建
	fwrite(&a, 4, 1, pf);//二进制形式写到文件中
	fclose(pf);
	pf = NULL;
	return 0;
}