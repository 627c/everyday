#define _CRT_SECURE_NO_WARNINGS
#include"Contact_Dynamic.h"
void InitContact(struct Contact* ps)
{
	ps->data = (struct PeoInfo*)malloc(3 * sizeof(struct PeoInfo));
	if (ps->data == NULL)
	{
		return;//直接返回，什么也不执行
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
}
void CheckCapacity(struct Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		//增容
		struct PeoInfo* ptr = realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));
		if(ptr!=NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("增容成功\n");
		}
		else
		{
			printf("增容失败\n");
		}
	}
}
void AddContact(struct Contact* ps)
{
	//检测当前通讯录容量
	//1.如果满了，就增加空间
	//2.如果未满，则不进行操作
	CheckCapacity(ps);
	//增加数据
	printf("请输入名字：");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入电话：");
	scanf("%s", ps->data[ps->size].tele);
	printf("请输入性别：");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入地址：");
	scanf("%s", ps->data[ps->size].addr);
	printf("请输入年龄：");
	scanf("%d", &(ps->data[ps->size].age));
	ps->size++;
	printf("添加成功\n");
	//if (ps->size == MAX)
	//{
	//	printf("通讯录已满，无法增加\n");
	//}
	//else
	//{
	//	printf("请输入名字：");
	//	scanf("%s", ps->data[ps->size].name);
	//	printf("请输入电话：");
	//	scanf("%s", ps->data[ps->size].tele);
	//	printf("请输入性别：");
	//	scanf("%s", ps->data[ps->size].sex);
	//	printf("请输入地址：");
	//	scanf("%s", ps->data[ps->size].addr);
	//	printf("请输入年龄：");
	//	scanf("%d", &(ps->data[ps->size].age));
	//	ps->size++;
	//	printf("添加成功\n");
	//}
}
void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-12s\t%-5s\t%-20s\t%-4s\n", "名字", "电话", "性别", "地址", "年龄");
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
	printf("请输入要删除人的名字：");
	scanf("%s", name);
	//1.查找要删除的人在什么位置
	int pos = FindByName(ps, name);//找到了返回名字所在元素的下标，找不到返回-1
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
	}
	else
	{
		//删除数据
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}
void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要查找人的名字：");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
	}
	else
	{
		printf("%-20s\t%-12s\t%-5s\t%-20s\t%-4s\n", "名字", "电话", "性别", "地址", "年龄");
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
	printf("请输入要修改人的名字：");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("要修改人的信息不存在\n");
	}
	else
	{
		printf("请输入名字：");
		scanf("%s", ps->data[pos].name);
		printf("请输入电话：");
		scanf("%s", ps->data[pos].tele);
		printf("请输入性别：");
		scanf("%s", ps->data[pos].sex);
		printf("请输入地址：");
		scanf("%s", ps->data[pos].addr);
		printf("请输入年龄：");
		scanf("%d", &(ps->data[pos].age));
		printf("修改完成\n");
	}
}
void SortContact(struct Contact* ps)
{

}
void DestoryContact(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}