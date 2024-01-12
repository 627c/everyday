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
	//SEEK_CUR 文件当前位置
	//SEEK_END 文件的末尾位置
	//SEEK_SET 文件的起始位置
	fseek(pf, -2, SEEK_END);
	//2.读取文件
	int ch = fgetc(pf);
	printf("%c\n", ch);
	return 0;
}