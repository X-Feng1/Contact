//��������ж�̬ͨѶ¼�Ĳ���

#include "Contact.h"

void menu()
{
	printf("************************************\n");
	printf("******        ��̬ͨѶ¼      ******\n");
	printf("******  1. ���      2. ɾ��  ******\n");
	printf("******  3. ����      4. �޸�  ******\n");
	printf("******  5. ��ʾ      0. �˳�  ******\n");
	printf("************************************\n");
}

int main()
{
	//����ͨѶ¼
	struct Contact con;
	//��ʼ��ͨѶ¼
	Initial_Contact(&con);
	int input = 0;
	do
	{
		menu();
		printf("������Ҫ���е�ѡ�>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
		{
			ADD_Contact(&con); //��ӳ�Ա��Ϣ
			break;
		}
		case DEL:
		{
			Del_element(&con); //ɾ����Ա��Ϣ
			break;
		}
		case SEARCH:
		{
			Search_elements(&con); //���ҳ�Ա��Ϣ
			break;
		}
		case MODIFY:
		{
			Modify_element(&con); //�޸ĳ�Ա��Ϣ
			break;
		}
		case SHOW:
		{
			Show_Contact(&con); //��ʾ��Ա��Ϣ
			break;
		}
		case EXIT:
		{
			printf("�˳�ͨѶ¼\n");
			break;
		}
		default:
		{
			printf("����������������룡\n");
			break;
		}
		}
	} while (input);
	return 0;

}