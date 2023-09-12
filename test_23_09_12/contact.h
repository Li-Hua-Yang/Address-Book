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


//类型声明
//联系人信息
typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}PeoInfo;

//通讯录声明
typedef	struct contact
{
	PeoInfo data[MAX];
	int count;		//记录通讯录联系人个数
}Contact;


//函数声明
//初始化函数
void InitContact(Contact* pc);
//添加联系人
void AddContact(Contact* pc);
//删除指定联系人
void DelContact(Contact* pc);
//查找联系人
void SearchContact(const Contact* pc);
//修改联系人
void ModifyContact(Contact* pc);
//联系人排序
void SortContact(Contact* pc);
//显示联系人
void ShowContact(const Contact* pc);


#endif	_CONTACT_H_