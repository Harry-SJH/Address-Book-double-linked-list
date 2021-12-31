#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phone
{
	char ID[10]; //���
	char name[20]; //����
	char street[15]; //�ֵ� 
	char city[20]; //����
	char post[10]; //�ʱ� 
	char state[10]; //���� 
}Ipa;//�����ͨѶ¼���ԵĽṹ��ȡ������

typedef struct List
{
	Ipa data;
	struct List *next;
}List;

List *L = NULL;
//1.��ʼ��ͨѶ¼,����ͷ�ڵ�
void InitList()
{
	L = (List *)malloc(sizeof(List));
	L->next = NULL;
	printf("Initialization Succeeded\n");
}


//2.����ͨѶ¼(β�巨)
void CreateList_Tail()
{
	List *node, *tail; //����ڵ��β�ڵ�
	tail = L;
	int count = 0;
	int flag = 1;
	while (flag)
	{
		count++;
		node = (List *)malloc(sizeof(List)); //���ڵ����ռ�
		printf("Enter %d data��", count);
		printf("ID��");
		scanf("%s", &(node->data.ID));
		//�ж�ID�Ƿ��ظ�
		List *p = L->next;
		while (p)
		{
			if (strcmp(p->data.ID, node->data.ID) == 0)
			{
				printf("ID is duplicate. Please re-enter it!\n");
				printf("ID��");
				scanf("%s", &(node->data.ID));
			}
			else
				p = p->next;
		}
		printf("Name��");
		scanf("%s", &(node->data.name));
		printf("Street��");
		scanf("%s", &(node->data.street));
		printf("City: ");
		scanf("%s", node->data.city);
		printf("Postcode: ");
		scanf("%s", node->data.post);
		printf("State: ");
		scanf("%s", node->data.state);
		tail->next = node;
		node->next = NULL; 
		tail =  node;
		printf("Whether to continue input (1. Continue 0: End)��");
		scanf("%d", &flag);
		if (flag == 0)
			break;
	}
}

//3.ɾ������(����IDɾ��)
void DelList()
{
	List *p = L->next;
	List *q = L;
	char ID[10];
	printf("Please enter the ID you want to delete��\n");
	scanf("%s", &ID);
	while (p && strcmp(p->data.ID, ID) != 0)
	{
		p = p->next;
		q = q->next;
	}
	if (p)
	{
		q->next = p->next;
		printf("Successfully Delete!\n");
		printf("The information about the deleted data is��\n");
		printf("ID��%s\n", p->data.ID);
		printf("Name��%s\n", p->data.name);
		printf("Street��%s\n", p->data.street);
		printf("City: %s\n", p->data.city);
		printf("Postcode: %s\n", p->data.post);
		printf("State: %s\n", p->data.state);
		free(p);
	}
	else
	{
		printf("This person's information does not exist in the contact��\n");
	}
}


//4.�޸�ͨѶ¼����
void UpdateList()
{
	List *p;
	p = L->next;
	char ID[10];
	printf("Enter the ID you want to change:\n");
	scanf("%s", &ID);
	while (p && strcmp(p->data.ID, ID) != 0)
	{
		p = p->next;
	}
	if (p != NULL)
	{
		int choice;
		printf("Please enter the attributes you want to modify (1. Name 2. Street 3. City 4. State)��\n");
		scanf("%d", &choice);
		if (choice == 1)
		{
			printf("Please enter a new name��");
			scanf("%s", &(p->data.name));
		}
		if (choice == 2)
		{
			printf("Please enter a new street��");
			scanf("%s", &(p->data.street));
		}
		if (choice == 3)
		{
			printf("Please enter a new city��");
			scanf("%s", &(p->data.city));
		}
		if (choice == 4)
		{
			printf("Please enter a new postcode��");
			scanf("%s", &(p->data.post));
		}
		if (choice == 5)
		{
			printf("Please enter a new state��");
			scanf("%s", &(p->data.state));
		}
		printf("Update Success��\n");
	}
	else
	{
		printf("ID does not exits!\n");
		return;
	}
}

//5.�������ݣ�ͨ��ID���ң�
void SearchList()
{
	List *p;
	char ID[10];
	p = L->next;
	printf("Please enter the ID you are looking for��\n");
	scanf("%s", &ID);
	while (p && strcmp(p->data.ID, ID) != 0)
	{
		p = p->next;
	}
	if (p == NULL)
	{
		printf("Does not exits��\n");
		return;
	}
	else
	{
		printf("\nID��%s\t", p->data.ID);
		printf("Name��%s\t", p->data.name);
		printf("Street��%s\t", p->data.street);
		printf("City��%s\t", p->data.city);
		printf("Postcode��%s\t", p->data.post);
		printf("State��%s\n", p->data.state);
	}
	
}

//6.����ͨѶ¼
void TraverseList()
{
	List *p;
	if (L == NULL)
	{
		printf("Empty��\n");
		return;
	}
	else
	{
		p = L->next;
		printf("All information is as follows��\n");
		while (p)
		{
			printf("\nID��%s\t", p->data.ID);
			printf("Name��%s\t", p->data.name);
			printf("Street��%s\t", p->data.street);
			printf("City��%s\t", p->data.city);
			printf("Postcode��%s\t", p->data.post);
			printf("State��%s\t\n", p->data.state);
			p = p->next;
		}
	}
}

//7.�ͷ�����
void DestroyList()
{
	List *p, *q;
	p = L->next;
	while (p)
	{
		q = p;//��q��ʱ��Ÿýڵ�
		p = p->next; //pָ����һ���ڵ�
		free(q);// �ͷŵ�ǰ�ڵ�
		q = NULL;
	}
	free(p);
	free(L);
	L = NULL;
	printf("Release Success��\n");
}

//void saveList()
//{
//    if (L->next == NULL)
//        return;
// 
//    FILE *fp;
//    if ((fp = fopen("list_file.txt", "w")) == NULL)
//        printf("...����ϵ���ļ�ʱ����...\n");
// 
//    person_node* ptr = L->next;
//    while (ptr != NULL)
//    {
//        fprintf(fp, "\n%s %s %s %s", ptr->data.name,ptr->data.street,ptr->data.city,ptr->data.post,ptr->data.state);
//        ptr = ptr->next;
//    }
//    fclose(fp);
//}

void Menu()
{
	printf("\n\t\t\t\t\t\t***********************191603134***�ξ��************************\n");
	printf("\t\t\t\t\t\t1.Initialize(Required)    2.New a Contact       3.Delete Contact\n");
	printf("\t\t\t\t\t\t4.Modify Contact          5.Search Contact      6.Traverse Contact\n");
	printf("\t\t\t\t\t\t                          7.Release Contact\n   8.Save the Contact");
	printf("\n\t\t\t\t\t\t***********************191603134***�ξ��************************\n");
}

int main()
{
	int choice;
	while (1)
	{
		Menu();
		printf("Please select one choice: \n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
		{
			//��ʼ��ͨѶ¼
			InitList();
			break;
		}
		case 2:
		{
			//����ͨѶ¼   β�巨
			CreateList_Tail();
			break;
		}
		case 3:
		{
			//ɾ����Ϣ
			DelList();
			break;
		}
		case 4:
		{
			//�޸���Ϣ
			UpdateList();
			break;
		}
		case 5:
		{
			//������Ϣ
			SearchList();
			break;
		}
		case 6:
		{
			//����ͨѶ¼
			TraverseList();
			break;
		}
		case 7:
		{
			//�ͷ�ͨѶ¼
			DestroyList();
			break;
		}
		case 8:
		{
			//�ͷ�ͨѶ¼
			saveList();
			break;
		}
		default:
			break;
		}
	}
	return 0;
}

