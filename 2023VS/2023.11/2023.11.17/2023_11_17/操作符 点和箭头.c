#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//����һ���ṹ������ struct Stu
struct Stu
{
	char name[20];
	int age;
	char id[20];
};
int main()
{
	int a = 10;
	//ʹ��struct Stu������ʹ�����һ��ѧ��������s1������ʼ��
	struct Stu s1 = { "����",20,"20231117" };
	struct Stu* ps = &s1;
	printf("%s\n", ps->name);  //�ṹ��ָ��->��Ա��
	printf("%s\n", (*ps).name);
	printf("%s\n", s1.name);   //.������
	printf("%d\n", s1.age);
	printf("%s\n", s1.id);
	//�ṹ�����.��Ա��
}