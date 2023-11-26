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
	Stu s = { "李四",40,"17234648878","男" };
	//打印结构体数据
	//Print1和Print2哪个更好---Print2更好，Print1需要开辟的空间更大，而且运行时间也更长，传址节省空间
	Print1(s);       //传参
	Print2(&s);     //传址
	return 0;
}