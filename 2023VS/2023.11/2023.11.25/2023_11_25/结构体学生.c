#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//描述一个学生，一些数据
//名字
//年龄
//电话
//性别
//struct 结构体关键字，Stu-结构体标签，struct Stu-结构体类型
//struct Stu
//{
//	char name[20];
//	short age;
//	char tele[12];
//	char sex[5];
//}s1,s2,s3;    //是三个全局的结构体变量
typedef struct Stu      //类型重命名
{
	char name[20];
	short age;
	char tele[12];
	char sex[5];
}Stu;       //类型
int main()
{
	struct Stu s1 = {"张三",20,"12345342676","男"};  //变量初始化
	Stu s2 = {"意义",30,"12356789876","保密"};
	return 0;
}