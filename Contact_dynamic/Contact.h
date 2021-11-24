#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define DEFAULT_CAPACITY 3
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_ADDR 30
#define MAX_SCHOOL 20

//������Ϣ�ṹ��
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char addr[MAX_ADDR];
	char school[MAX_SCHOOL];
};


//ͨѶ¼�ṹ��
struct Contact
{
	struct PeoInfo* data;
	int size; //��¼ͨѶ¼�еĳ�Ա����
	int capacity;//��¼ͨѶ¼���������
};

enum SELECT
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW
};

enum Charact
{
	EXT,
	NAME,
	AGE,
	SEX,
	ADDR,
	SCHOOL
};


void Initial_Contact(struct Contact* ps); //��ʼ��ͨѶ¼

void ADD_Contact(struct Contact* ps); //���ӳ�Ա��Ϣ
void Del_element(struct Contact* ps); //ɾ����Ա��Ϣ
void Search_elements(struct Contact* ps);//���ҳ�Ա��Ϣ
void Modify_element(struct Contact* ps); //�޸ĳ�Ա��Ϣ
void Show_Contact(struct Contact* ps);//��ʾͨѶ¼

