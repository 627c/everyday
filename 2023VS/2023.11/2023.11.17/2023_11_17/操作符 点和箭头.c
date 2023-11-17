#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//创建一个结构体类型 struct Stu
struct Stu
{
	char name[20];
	int age;
	char id[20];
};
int main()
{
	int a = 10;
	//使用struct Stu这个类型创建了一个学生对象是s1，并初始化
	struct Stu s1 = { "张三",20,"20231117" };
	struct Stu* ps = &s1;
	printf("%s\n", ps->name);  //结构体指针->成员名
	printf("%s\n", (*ps).name);
	printf("%s\n", s1.name);   //.操作符
	printf("%d\n", s1.age);
	printf("%s\n", s1.id);
	//结构体变量.成员名
}