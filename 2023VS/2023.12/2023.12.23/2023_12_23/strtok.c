#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	char str[] = "liuanqi@jiangnan.edu";
	char* p = "@.";
	char* ret = NULL;
	for (ret = strtok(str, p); ret != NULL; ret = strtok(NULL, p))
	{
		printf("%s\n", ret);
	}
	//printf("%s\n",strtok(str, p));
	//printf("%s\n", strtok(NULL, p));
	//printf("%s\n", strtok(NULL, p));
	return 0;
}