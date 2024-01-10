#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<errno.h>
int main()
{
	FILE* pfRead = fopen("test.txt", "r");
	if (pfRead == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;//直接返回，不进行后面操作
	}
	//读文件
	printf("%c",fgetc(pfRead));
	printf("%c", fgetc(pfRead));
	printf("%c", fgetc(pfRead));
	//关闭文件
	fclose(pfRead);
	pfRead = NULL;
	return 0;
}