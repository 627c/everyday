#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
#include<errno.h>
int main()
{
	char buf[1024] = { 0 };
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL)
	{
		return 0;
	}
	//写文件
	fputs("hello", pf);//无换行
	fputs("world", pf);
	fclose(pf);
	pf = NULL;
	return 0;
}