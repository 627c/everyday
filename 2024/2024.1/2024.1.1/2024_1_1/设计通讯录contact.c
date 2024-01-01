#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"
void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;//����ͨѶ¼���ֻ��0��Ԫ��
}
void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("ͨѶ¼�������޷�����\n");
	}
	else
	{
		printf("���������֣�");
		scanf("%s", ps->data[ps->size].name);
		printf("������绰��");
		scanf("%s", ps->data[ps->size].tele);
		printf("�������Ա�");
		scanf("%s", ps->data[ps->size].sex);
		printf("�������ַ��");
		scanf("%s", ps->data[ps->size].addr);
		printf("���������䣺");
		scanf("%d", &(ps->data[ps->size].age));
		ps->size++;
		printf("��ӳɹ�\n");
	}
}
void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-12s\t%-5s\t%-20s\t%-4s\n", "����", "�绰", "�Ա�", "��ַ", "����");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-12s\t%-5s\t%-20s\t%-4d\n",
				ps->data[i].name,
				ps->data[i].tele,
				ps->data[i].sex,
				ps->data[i].addr,
				ps->data[i].age);
		}
	}
}
static int FindByName(struct Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
			return i;
	}
	return -1;
}
void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫɾ���˵����֣�");
	scanf("%s", name);
	//1.����Ҫɾ��������ʲôλ��
	int pos = FindByName(ps, name);//�ҵ��˷�����������Ԫ�ص��±꣬�Ҳ�������-1
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
	}
	else
	{
		//ɾ������
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}
void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�����˵����֣�");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
	}
	else
	{
		printf("%-20s\t%-12s\t%-5s\t%-20s\t%-4s\n", "����", "�绰", "�Ա�", "��ַ", "����");
		printf("%-20s\t%-12s\t%-5s\t%-20s\t%-4d\n",
			ps->data[pos].name,
			ps->data[pos].tele,
			ps->data[pos].sex,
			ps->data[pos].addr,
			ps->data[pos].age);
	}
}
void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�޸��˵����֣�");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("Ҫ�޸��˵���Ϣ������\n");
	}
	else
	{
		printf("���������֣�");
		scanf("%s", ps->data[pos].name);
		printf("������绰��");
		scanf("%s", ps->data[pos].tele);
		printf("�������Ա�");
		scanf("%s", ps->data[pos].sex);
		printf("�������ַ��");
		scanf("%s", ps->data[pos].addr);
		printf("���������䣺");
		scanf("%d", &(ps->data[pos].age));
		printf("�޸����\n");
	}
}