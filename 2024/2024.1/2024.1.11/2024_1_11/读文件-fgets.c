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
	//���ļ�
	fgets(buf, 1024, pf);
	printf("%s", buf);//buf�д����hello\n,���ӡ������
	fgets(buf, 1024, pf);
	printf("%s", buf);
	fclose(pf);
	pf = NULL;
	return 0;
}