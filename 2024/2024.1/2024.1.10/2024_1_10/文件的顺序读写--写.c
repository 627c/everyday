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
		return 0;//ֱ�ӷ��أ������к������
	}
	//д�ļ�
	fputc('b', pfWrite);
	fputc('c', pfWrite);
	fputc('d', pfWrite);
	//�ر��ļ�
	fclose(pfWrite);
	pfWrite = NULL;
	return 0;
}