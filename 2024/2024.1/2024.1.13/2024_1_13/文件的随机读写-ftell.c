#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		return 0;
	}
	//1.定位文件指针
	fseek(pf, -2, SEEK_END);
	int pos = ftell(pf);
	printf("%d\n", pos);
	fclose(pf);
	pf = NULL;
	return 0;
}