#include "Contact.h"


void menu2()
{
	printf("***********************\n");
	printf("** 1. ����   2. ���� **\n");
	printf("** 3. �Ա�   4. ��ַ **\n");
	printf("** 5. ѧУ   0. �˳� **\n");
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
		printf("����ʧ��\n");
	else
	{
		printf("���ݳɹ�\n");
		ps->data = ptr;
		ps->capacity += 2;
	}
}

//���ӳ�Ա��Ϣ
void ADD_Contact(struct Contact* ps)
{
	//�жϿռ��Ƿ����������������ݣ�������ӳ�Ա��Ϣ
	if (ps->size == ps->capacity)
	{
		ADD_Capacity(ps);
	}
	printf("������Ҫ��ӳ�Ա��������>");
	scanf("%s", ps->data[ps->size].name);
	printf("������Ҫ��ӳ�Ա�����䣺>");		
	scanf("%d", &(ps->data[ps->size].age));
	printf("������Ҫ��ӳ�Ա���Ա�>");
	scanf("%s", ps->data[ps->size].sex);
	printf("������Ҫ��ӳ�Ա�ĵ�ַ��>");
	scanf("%s", ps->data[ps->size].addr);
	printf("������Ҫ��ӳ�Ա��ѧУ��>");
	scanf("%s", ps->data[ps->size].school);
	ps->size++;
	printf("��ӳɹ�\n");
}

//����������ѯ��Ա�������򷵻��±꣬�������򷵻�-1
int Find_element(struct Contact* ps,char* name)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
			return i;
	}
	printf("��ѯ�ĳ�Ա������\n");
	return -1;
}

//ɾ����Ա��Ϣ
void Del_element(struct Contact* ps)
{
	char name[MAX_NAME] = { 0 };
	int i = 0;
	printf("������Ҫɾ����Ա��������>");
	scanf("%s", name);
	i = Find_element(ps, name);
	if (i >= 0)
	{
		memcpy(&(ps->data[i]), &(ps->data[i + 1]), sizeof(struct PeoInfo) * (ps->size - i - 1));
		ps->size--;
	}
}


//���ҳ�Ա��Ϣ����������ʾ
void Search_elements(struct Contact* ps)
{
	char name[MAX_NAME] = { 0 };
	int i = 0;
	printf("������Ҫ���ҵĳ�Ա������>");
	scanf("%s", name);
	i = Find_element(ps,name);
	if (i >= 0)
	{
		printf("%-20s\t%-4s\t%-5s\t%-30s\t%-20s\n", "����", "����", "�Ա�", "��ַ", "ѧУ");
		printf("%-20s\t%-4d\t%-5s\t%-30s\t%-20s\n",
			ps->data[i].name,
			ps->data[i].age,
			ps->data[i].sex,
			ps->data[i].addr,
			ps->data[i].school);
	}
}



//�޸ĳ�Ա��Ϣ
void Modify_element(struct Contact* ps)
{
	int i = 0;
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�޸ĳ�Ա��������>");
	scanf("%s", name);
	i = Find_element(ps, name);
	if (i >= 0)
	{
		int input = 0;
		do
		{
			menu2();
			printf("������Ҫ�޸ĵ�Ҫ�أ�>");
			scanf("%d", &input);
			switch (input)
			{
			case NAME:
			{
				char name[MAX_NAME] = { 0 };
				printf("������Ҫ�޸ĺ�����ݣ�>");
				scanf("%s", name);
				strcpy((char*)&(ps->data[i].name),name);
				break;
			}
			case AGE:
			{
				int age = 0;
				printf("������Ҫ�޸ĺ�����ݣ�>");
				scanf("%d", &age);
				memcpy((&ps->data[i].age), &age, sizeof(age));
				break;
			}
			case SEX:
			{
				char sex[MAX_SEX] = { 0 };
				printf("������Ҫ�޸ĺ�����ݣ�>");
				scanf("%s", sex);
				strcpy((char*)&(ps->data[i].sex),sex);
				break;
			}
			case ADDR:
			{
				char addr[MAX_ADDR] = { 0 };
				printf("������Ҫ�޸ĺ�����ݣ�>");
				scanf("%s", addr);
				strcpy((char*)&(ps->data[i].addr),addr);
				break;
			}
			case SCHOOL:
			{
				char school[MAX_SCHOOL] = { 0 };
				printf("������Ҫ�޸ĺ�����ݣ�>");
				scanf("%s", school);
				strcpy((char*)&(ps->data[i].school),school);
				break;
			}
			case EXT:
			{
				printf("�˳��޸�\n");
				break;
			}
			default:
			{
				printf("����������������룡\n");
				break;
			}
			}
		} while (input);
	}
}


//��ʾ��Ա��Ϣ
void Show_Contact(struct Contact* ps)
{
	int i = 0;

	printf("%-20s\t%-4s\t%-5s\t%-30s\t%-20s\n", "����", "����", "�Ա�", "��ַ", "ѧУ");

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