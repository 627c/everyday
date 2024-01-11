#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
#include<errno.h>
int main()
{
	char buf[1024] = { 0 };
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		return 0;
	}
	//读文件
	fgets(buf, 1024, pf);
	printf("%s", buf);//buf中存的是hello\n,会打印出换行
	fgets(buf, 1024, pf);
	printf("%s", buf);
	fclose(pf);
	pf = NULL;
	return 0;
}