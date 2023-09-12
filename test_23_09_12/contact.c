#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

//初始化
void InitContact(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

//添加联系人
void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->count < MAX)
	{
		printf("请输入姓名:>");
		scanf("%s", pc->data[pc->count].name);
		printf("请输入年龄:>");
		scanf("%d", &(pc->data[pc->count].age));
		printf("请输入性别:>");
		scanf("%s", pc->data[pc->count].sex);
		printf("请输入电话:>");
		scanf("%s", pc->data[pc->count].tel);
		printf("请输入地址:>");
		scanf("%s", pc->data[pc->count].addr);
		pc->count++;
		printf("成功添加联系人\n");
	}
	else
		printf("通讯录已满\n");
}

//查找联系人
static int FindByName(const Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

//删除指定联系人
void DelContact(Contact* pc)
{
	assert(pc);
	char name[NAME_MAX] = { 0 };
	printf("输入被删除联系人的姓名:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("未找到联系人\n");
		return;
	}
	int i = 0;
	for (i = pos; i < pc->count - 1; i++)
	{
			pc->data[i] = pc->data[i + 1];
	}
	printf("删除成功\n");
	pc->count--;
	
}

//查找联系人
void SearchContact(const Contact* pc)
{
	assert(pc);
	char name[NAME_MAX] = { 0 };
	printf("输入查找联系人的姓名:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("未找到联系人\n");
	}
	else
	{
		printf("%20s\t%5d\t%10s\t%11s\t%30s\n", pc->data[pos].name,
												pc->data[pos].age,
												pc->data[pos].sex,
												pc->data[pos].tel,
												pc->data[pos].addr);
		
	}
}

//修改联系人
void ModifyContact(Contact* pc)
{
	assert(pc);
	char name[NAME_MAX] = { 0 };
	printf("输入修改联系人的姓名:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("未找到联系人\n");
	}
	else
	{
		printf("请输入姓名:>");
		scanf("%s", pc->data[pos].name);
		printf("请输入年龄:>");
		scanf("%d", &(pc->data[pos].age));
		printf("请输入性别:>");
		scanf("%s", pc->data[pos].sex);
		printf("请输入电话:>");
		scanf("%s", pc->data[pos].tel);
		printf("请输入地址:>");
		scanf("%s", pc->data[pos].addr);
		printf("修改成功\n");
	}
}

//按名字排序
int SortByName(const void* p1, const void* p2)
{
	const char* name1 = (char*)p1;
	const char* name2 = (char*)p2;
	return (strcmp(name1, name2));
}
//联系人排序
void SortContact(Contact* pc)
{
	int i = 0;
	qsort(pc->data, pc->count, sizeof(pc->data[0]), SortByName);
	printf("排序成功\n");
}

//显示联系人
void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%20s\t%5s\t%10s\t%11s\t%30s\n", "姓名", "年龄", "性别", "电话", "地址");
	for (i = 0; i < pc->count; i++)
	{
		printf("%20s\t%5d\t%10s\t%11s\t%30s\n", pc->data[i].name,
												pc->data[i].age,
												pc->data[i].sex,
												pc->data[i].tel,
												pc->data[i].addr);
	}
}