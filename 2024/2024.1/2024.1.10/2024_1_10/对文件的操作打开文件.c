#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<errno.h>
int main()
{
	//����·����ǰ����һ��б����ת��
	//..��ʾ��һ��·��
	// fopen("..\\..\\text.txt","r")
	//.��ʾ��ǰ·��
	FILE* pf = fopen("D:\\ÿ��һ��\\everyday\\2024\\2024.1\\2024.1.9\\2024_1_9\\test.txt", "r");
	//�򿪳ɹ��������ļ���Ϣ����FILE�ṹ�壩�ĵ�ַ����ʧ�ܣ����ؿ�ָ�룬NULL
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;//ֱ�ӷ��أ������к������
	}
	//�򿪳ɹ�
	//���ļ�
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}