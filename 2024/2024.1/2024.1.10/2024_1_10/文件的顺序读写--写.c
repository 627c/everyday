#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<errno.h>
int main()
{
	FILE* pfWrite = fopen("test.txt", "w");
	if (pfWrite == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;//直接返回，不进行后面操作
	}
	//写文件
	fputc('b', pfWrite);
	fputc('c', pfWrite);
	fputc('d', pfWrite);
	//关闭文件
	fclose(pfWrite);
	pfWrite = NULL;
	return 0;
}