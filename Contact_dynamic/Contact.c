#include "Contact.h"


void menu2()
{
	printf("***********************\n");
	printf("** 1. 姓名   2. 年龄 **\n");
	printf("** 3. 性别   4. 地址 **\n");
	printf("** 5. 学校   0. 退出 **\n");
	printf("***********************\n");

}

void Initial_Contact(struct Contact* ps)
{
	ps->data = (struct PeoInfo*)malloc(DEFAULT_CAPACITY * sizeof(struct PeoInfo));
	ps->size = 0;
	ps->capacity = DEFAULT_CAPACITY;
}


void ADD_Capacity(struct Contact* ps)
{
	struct PeoInfo* ptr = (struct PeoInfo*)realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));
	if (ptr == NULL)
		printf("扩容失败\n");
	else
	{
		printf("扩容成功\n");
		ps->data = ptr;
		ps->capacity += 2;
	}
}

//增加成员信息
void ADD_Contact(struct Contact* ps)
{
	//判断空间是否已满，若满则扩容，否则添加成员信息
	if (ps->size == ps->capacity)
	{
		ADD_Capacity(ps);
	}
	printf("请输入要添加成员的姓名：>");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入要添加成员的年龄：>");		
	scanf("%d", &(ps->data[ps->size].age));
	printf("请输入要添加成员的性别：>");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入要添加成员的地址：>");
	scanf("%s", ps->data[ps->size].addr);
	printf("请输入要添加成员的学校：>");
	scanf("%s", ps->data[ps->size].school);
	ps->size++;
	printf("添加成功\n");
}

//依据姓名查询成员，存在则返回下标，不存在则返回-1
int Find_element(struct Contact* ps,char* name)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
			return i;
	}
	printf("查询的成员不存在\n");
	return -1;
}

//删除成员信息
void Del_element(struct Contact* ps)
{
	char name[MAX_NAME] = { 0 };
	int i = 0;
	printf("请输入要删除成员的姓名：>");
	scanf("%s", name);
	i = Find_element(ps, name);
	if (i >= 0)
	{
		memcpy(&(ps->data[i]), &(ps->data[i + 1]), sizeof(struct PeoInfo) * (ps->size - i - 1));
		ps->size--;
	}
}


//查找成员信息，并进行显示
void Search_elements(struct Contact* ps)
{
	char name[MAX_NAME] = { 0 };
	int i = 0;
	printf("请输入要查找的成员姓名：>");
	scanf("%s", name);
	i = Find_element(ps,name);
	if (i >= 0)
	{
		printf("%-20s\t%-4s\t%-5s\t%-30s\t%-20s\n", "姓名", "年龄", "性别", "地址", "学校");
		printf("%-20s\t%-4d\t%-5s\t%-30s\t%-20s\n",
			ps->data[i].name,
			ps->data[i].age,
			ps->data[i].sex,
			ps->data[i].addr,
			ps->data[i].school);
	}
}



//修改成员信息
void Modify_element(struct Contact* ps)
{
	int i = 0;
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改成员的姓名：>");
	scanf("%s", name);
	i = Find_element(ps, name);
	if (i >= 0)
	{
		int input = 0;
		do
		{
			menu2();
			printf("请输入要修改的要素：>");
			scanf("%d", &input);
			switch (input)
			{
			case NAME:
			{
				char name[MAX_NAME] = { 0 };
				printf("请输入要修改后的内容：>");
				scanf("%s", name);
				strcpy((char*)&(ps->data[i].name),name);
				break;
			}
			case AGE:
			{
				int age = 0;
				printf("请输入要修改后的内容：>");
				scanf("%d", &age);
				memcpy((&ps->data[i].age), &age, sizeof(age));
				break;
			}
			case SEX:
			{
				char sex[MAX_SEX] = { 0 };
				printf("请输入要修改后的内容：>");
				scanf("%s", sex);
				strcpy((char*)&(ps->data[i].sex),sex);
				break;
			}
			case ADDR:
			{
				char addr[MAX_ADDR] = { 0 };
				printf("请输入要修改后的内容：>");
				scanf("%s", addr);
				strcpy((char*)&(ps->data[i].addr),addr);
				break;
			}
			case SCHOOL:
			{
				char school[MAX_SCHOOL] = { 0 };
				printf("请输入要修改后的内容：>");
				scanf("%s", school);
				strcpy((char*)&(ps->data[i].school),school);
				break;
			}
			case EXT:
			{
				printf("退出修改\n");
				break;
			}
			default:
			{
				printf("输入错误，请重新输入！\n");
				break;
			}
			}
		} while (input);
	}
}


//显示成员信息
void Show_Contact(struct Contact* ps)
{
	int i = 0;

	printf("%-20s\t%-4s\t%-5s\t%-30s\t%-20s\n", "姓名", "年龄", "性别", "地址", "学校");

	for (i = 0; i < ps->size; i++)
	{
		printf("%-20s\t%-4d\t%-5s\t%-30s\t%-20s\n",
			ps->data[i].name,
			ps->data[i].age,
			ps->data[i].sex,
			ps->data[i].addr,
			ps->data[i].school);
	}

}