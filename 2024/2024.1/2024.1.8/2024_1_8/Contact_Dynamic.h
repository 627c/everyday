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
	struct PeoInfo* data;//ָ��һ��ռ䣬ͨѶ¼��С
	int size;//��¼��ǰ�Ѿ��е�Ԫ��
	int capacity;//��¼��ǰͨѶ¼�������
};
//��������
//��ʼ��ͨѶ¼�ĺ���
void InitContact(struct Contact* ps);
//����һ����Ϣ��ͨѶ¼
void AddContact(struct Contact* ps);
//��ӡͨѶ¼�е���Ϣ
void ShowContact(const struct Contact* ps);
//ɾ��ָ����ϵ��
void DelContact(struct Contact* ps);
//����ָ���˵���Ϣ
void SearchContact(const struct Contact* ps);
//�޸�ָ����ϵ��
void ModifyContact(struct Contact* ps);
//����ͨѶ¼����
void SortContact(struct Contact* ps);
//�����̬���ٵĿռ�
void DestoryContact(struct Contact* ps);