#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//����һ��ѧ����һЩ����
//����
//����
//�绰
//�Ա�
//struct �ṹ��ؼ��֣�Stu-�ṹ���ǩ��struct Stu-�ṹ������
//struct Stu
//{
//	char name[20];
//	short age;
//	char tele[12];
//	char sex[5];
//}s1,s2,s3;    //������ȫ�ֵĽṹ�����
typedef struct Stu      //����������
{
	char name[20];
	short age;
	char tele[12];
	char sex[5];
}Stu;       //����
int main()
{
	struct Stu s1 = {"����",20,"12345342676","��"};  //������ʼ��
	Stu s2 = {"����",30,"12356789876","����"};
	return 0;
}