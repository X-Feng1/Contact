//本程序进行动态通讯录的测试

#include "Contact.h"

void menu()
{
	printf("************************************\n");
	printf("******        动态通讯录      ******\n");
	printf("******  1. 添加      2. 删除  ******\n");
	printf("******  3. 查找      4. 修改  ******\n");
	printf("******  5. 显示      0. 退出  ******\n");
	printf("************************************\n");
}

int main()
{
	//创建通讯录
	struct Contact con;
	//初始化通讯录
	Initial_Contact(&con);
	int input = 0;
	do
	{
		menu();
		printf("请输入要进行的选项：>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
		{
			ADD_Contact(&con); //添加成员信息
			break;
		}
		case DEL:
		{
			Del_element(&con); //删除成员信息
			break;
		}
		case SEARCH:
		{
			Search_elements(&con); //查找成员信息
			break;
		}
		case MODIFY:
		{
			Modify_element(&con); //修改成员信息
			break;
		}
		case SHOW:
		{
			Show_Contact(&con); //显示成员信息
			break;
		}
		case EXIT:
		{
			printf("退出通讯录\n");
			break;
		}
		default:
		{
			printf("输入错误，请重新输入！\n");
			break;
		}
		}
	} while (input);
	return 0;

}