#define _CRT_SECURE_NO_WARNINGS 1


//***************************************//
//*********		 ģ��ͨѶ¼		*********//
//*********      Li Huayang		*********//
//*********      2023/09/11		*********//
//***************************************//


#include "contact.h"

//ͨѶ¼����
//��Ա��Ϣ������+����+�Ա�+�绰+��ַ
//1�����100���˵���Ϣ
//2�������ϵ��
//3��ɾ��ָ����ϵ��
//4��������ϵ��
//5���޸���ϵ��
//6������
//7����ʾ��ϵ��

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
	//��ʼ��ͨѶ¼
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
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("���������������\n");
		}
	} while (input);
	return 0;
}