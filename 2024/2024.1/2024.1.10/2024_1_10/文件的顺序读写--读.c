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
		return 0;//ֱ�ӷ��أ������к������
	}
	//���ļ�
	printf("%c",fgetc(pfRead));
	printf("%c", fgetc(pfRead));
	printf("%c", fgetc(pfRead));
	//�ر��ļ�
	fclose(pfRead);
	pfRead = NULL;
	return 0;
}