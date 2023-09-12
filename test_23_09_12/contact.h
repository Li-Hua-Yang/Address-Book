#ifndef _CONTACT_H_
#define _CONTACT_H_

#pragma once
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <search.h>

#define MAX 100
#define NAME_MAX 20
#define SEX_MAX 10
#define TEL_MAX 11
#define ADDR_MAX 30


//��������
//��ϵ����Ϣ
typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}PeoInfo;

//ͨѶ¼����
typedef	struct contact
{
	PeoInfo data[MAX];
	int count;		//��¼ͨѶ¼��ϵ�˸���
}Contact;


//��������
//��ʼ������
void InitContact(Contact* pc);
//�����ϵ��
void AddContact(Contact* pc);
//ɾ��ָ����ϵ��
void DelContact(Contact* pc);
//������ϵ��
void SearchContact(const Contact* pc);
//�޸���ϵ��
void ModifyContact(Contact* pc);
//��ϵ������
void SortContact(Contact* pc);
//��ʾ��ϵ��
void ShowContact(const Contact* pc);


#endif	_CONTACT_H_