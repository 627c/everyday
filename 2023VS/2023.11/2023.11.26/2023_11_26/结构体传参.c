#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
typedef struct Stu
{
	char name[20];
	short age;
	char tele[12];
	char sex[5];
}Stu;
void Print1(Stu tmp)
{
	printf("name:%s\n", tmp.name);
	printf("age:%d\n", tmp.age);
	printf("tele:%s\n", tmp.tele);
	printf("sex:%s\n", tmp.sex);
}
void Print2(Stu* ps)
{
	printf("name:%s\n", ps->name);
	printf("age:%d\n", ps->age);
	printf("tele:%s\n", ps->tele);
	printf("sex:%s\n", ps->sex);
}
int main()
{
	Stu s = { "����",40,"17234648878","��" };
	//��ӡ�ṹ������
	//Print1��Print2�ĸ�����---Print2���ã�Print1��Ҫ���ٵĿռ���󣬶�������ʱ��Ҳ��������ַ��ʡ�ռ�
	Print1(s);       //����
	Print2(&s);     //��ַ
	return 0;
}