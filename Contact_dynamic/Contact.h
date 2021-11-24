#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define DEFAULT_CAPACITY 3
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_ADDR 30
#define MAX_SCHOOL 20

//个人信息结构体
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char addr[MAX_ADDR];
	char school[MAX_SCHOOL];
};


//通讯录结构体
struct Contact
{
	struct PeoInfo* data;
	int size; //记录通讯录中的成员数量
	int capacity;//记录通讯录的最大容量
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


void Initial_Contact(struct Contact* ps); //初始化通讯录

void ADD_Contact(struct Contact* ps); //增加成员信息
void Del_element(struct Contact* ps); //删除成员信息
void Search_elements(struct Contact* ps);//查找成员信息
void Modify_element(struct Contact* ps); //修改成员信息
void Show_Contact(struct Contact* ps);//显示通讯录

