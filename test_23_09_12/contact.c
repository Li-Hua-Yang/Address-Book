#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

//��ʼ��
void InitContact(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

//�����ϵ��
void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->count < MAX)
	{
		printf("����������:>");
		scanf("%s", pc->data[pc->count].name);
		printf("����������:>");
		scanf("%d", &(pc->data[pc->count].age));
		printf("�������Ա�:>");
		scanf("%s", pc->data[pc->count].sex);
		printf("������绰:>");
		scanf("%s", pc->data[pc->count].tel);
		printf("�������ַ:>");
		scanf("%s", pc->data[pc->count].addr);
		pc->count++;
		printf("�ɹ������ϵ��\n");
	}
	else
		printf("ͨѶ¼����\n");
}

//������ϵ��
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

//ɾ��ָ����ϵ��
void DelContact(Contact* pc)
{
	assert(pc);
	char name[NAME_MAX] = { 0 };
	printf("���뱻ɾ����ϵ�˵�����:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("δ�ҵ���ϵ��\n");
		return;
	}
	int i = 0;
	for (i = pos; i < pc->count - 1; i++)
	{
			pc->data[i] = pc->data[i + 1];
	}
	printf("ɾ���ɹ�\n");
	pc->count--;
	
}

//������ϵ��
void SearchContact(const Contact* pc)
{
	assert(pc);
	char name[NAME_MAX] = { 0 };
	printf("���������ϵ�˵�����:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("δ�ҵ���ϵ��\n");
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

//�޸���ϵ��
void ModifyContact(Contact* pc)
{
	assert(pc);
	char name[NAME_MAX] = { 0 };
	printf("�����޸���ϵ�˵�����:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("δ�ҵ���ϵ��\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", pc->data[pos].name);
		printf("����������:>");
		scanf("%d", &(pc->data[pos].age));
		printf("�������Ա�:>");
		scanf("%s", pc->data[pos].sex);
		printf("������绰:>");
		scanf("%s", pc->data[pos].tel);
		printf("�������ַ:>");
		scanf("%s", pc->data[pos].addr);
		printf("�޸ĳɹ�\n");
	}
}

//����������
int SortByName(const void* p1, const void* p2)
{
	const char* name1 = (char*)p1;
	const char* name2 = (char*)p2;
	return (strcmp(name1, name2));
}
//��ϵ������
void SortContact(Contact* pc)
{
	int i = 0;
	qsort(pc->data, pc->count, sizeof(pc->data[0]), SortByName);
	printf("����ɹ�\n");
}

//��ʾ��ϵ��
void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%20s\t%5s\t%10s\t%11s\t%30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < pc->count; i++)
	{
		printf("%20s\t%5d\t%10s\t%11s\t%30s\n", pc->data[i].name,
												pc->data[i].age,
												pc->data[i].sex,
												pc->data[i].tel,
												pc->data[i].addr);
	}
}