#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<errno.h>
struct S
{
	char name[20];
	int age;
	double score;
};
int main()
{
	struct S s = { "����",20,55.6 };
	FILE* pf = fopen("test.txt", "wb");
	if (pf == NULL)
	{
		return 0;
	}
	//�����Ƶ���ʽд�ļ�
	fwrite(&s, sizeof(struct S), 1, pf);
	fclose(pf);
	pf = NULL;
	return 0;
}