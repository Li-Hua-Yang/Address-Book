#define _CRT_SECURE_NO_WARNINGS 1


//***************************************//
//*********		 模拟通讯录		*********//
//*********      Li Huayang		*********//
//*********      2023/09/11		*********//
//***************************************//


#include "contact.h"

//通讯录功能
//人员信息：名字+年龄+性别+电话+地址
//1、存放100个人的信息
//2、添加联系人
//3、删除指定联系人
//4、查找联系人
//5、修改联系人
//6、排序
//7、显示联系人

void menu()
{
	printf("**************************************\n");
	printf("******  1. add      2. del      ******\n");
	printf("******  3. search   4. modify   ******\n");
	printf("******  5. sort     6. show     ******\n");
	printf("******  0. exit                 ******\n");
	printf("**************************************\n");
}

int main()
{
	int input = 0;
	Contact con;
	//初始化通讯录
	InitContact(&con);
	do 
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			AddContact(&con);
			break;
		case 2:
			DelContact(&con);
			break;
		case 3:
			SearchContact(&con);
			break;
		case 4:
			ModifyContact(&con);
			break;
		case 5:
			SortContact(&con);
			break;
		case 6:
			ShowContact(&con);
			break;
		case 0:
			printf("退出通讯录\n");
			break;
		default:
			printf("输入错误，重新输入\n");
		}
	} while (input);
	return 0;
}