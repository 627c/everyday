#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<errno.h>
int main()
{
	//绝对路径，前面多加一个斜杠来转义
	//..表示上一级路径
	// fopen("..\\..\\text.txt","r")
	//.表示当前路径
	FILE* pf = fopen("D:\\每日一题\\everyday\\2024\\2024.1\\2024.1.9\\2024_1_9\\test.txt", "r");
	//打开成功，返回文件信息区（FILE结构体）的地址；打开失败，返回空指针，NULL
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;//直接返回，不进行后面操作
	}
	//打开成功
	//读文件
	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}