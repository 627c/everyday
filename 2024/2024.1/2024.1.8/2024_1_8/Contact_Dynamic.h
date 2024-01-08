#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#define MAX 1000
#define MAX_NAME 20
#define MAX_TELE 12
#define MAX_SEX 5
#define MAX_ADDR 30
#define DEFAULT_SZ 3
struct PeoInfo
{
	char name[MAX_NAME];
	char tele[MAX_TELE];
	char sex[MAX_SEX];
	char addr[MAX_ADDR];
	int age;
};
struct Contact
{
	struct PeoInfo* data;//指向一块空间，通讯录大小
	int size;//记录当前已经有的元素
	int capacity;//记录当前通讯录最大容量
};
//声明函数
//初始化通讯录的函数
void InitContact(struct Contact* ps);
//增加一个信息到通讯录
void AddContact(struct Contact* ps);
//打印通讯录中的信息
void ShowContact(const struct Contact* ps);
//删除指定联系人
void DelContact(struct Contact* ps);
//查找指定人的信息
void SearchContact(const struct Contact* ps);
//修改指定联系人
void ModifyContact(struct Contact* ps);
//排序通讯录内容
void SortContact(struct Contact* ps);
//清除动态开辟的空间
void DestoryContact(struct Contact* ps);