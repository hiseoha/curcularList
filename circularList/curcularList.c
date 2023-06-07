#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

//���� �޽��� ���
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	return;
}

void init_list(ListNode** head) {
    *head = NULL;
}

//ù ��° ��忡 �� �߰�
ListNode* insert_first(ListNode* head, element data)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = data;

	if (head == NULL) {
		head = newNode;
		newNode->link = head;
	}
	else {
		newNode->link = head->link;
		head->link = newNode;
	}
	return head; 
}

//������ ��忡 �� �߰�
ListNode* insert_last(ListNode* head, element data)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = data;
	if (head == NULL) {
		head = newNode;
		newNode->link = head;
	}
	else {
		newNode->link = head->link;
		head->link = newNode;
		head = newNode;
	}
	return head;
}

//ù ��° ��� ����
ListNode* delete_first(ListNode* head)
{
	if (head == NULL) {
		error("List is Empty.");
		return;
	}

	//����Ʈ ������ ���
	ListNode* lastNode = head;
	while (lastNode->link != head) {
		lastNode = lastNode->link;
	}

	//head�� ���� ���� ����
	ListNode* temp = head;
	head = (head)->link;
	lastNode->link = head;

	free(temp);
	return head;
}

//������ ��� ����
ListNode* delete_last(ListNode* head)
{
	if (head == NULL) {
		error("List is Empty.");
		return;
	}
	//����Ʈ ������ ���
	ListNode* last = head;
	ListNode* prev = NULL;
	while (last->link != head) {
		prev = last;
		last = last->link;
	}
	// ������ ��� ����
	if (prev != NULL) {
		prev->link = head;
	}
	else {
		head = NULL;
	}
	free(last);
	return head;
}

//����Ʈ ���
void print_list(ListNode* head)
{
	ListNode* p;

	if (head == NULL) {
		error("List is Empty.");
		return;
	}
	p = head->link;
	while (p == head->link) {
		printf("%d -> ", p->data);
		p = p->link;
	}
	printf("\n");
}

int main(void)
{
	ListNode* head;
	init_list(&head);

	int choice, num;

	while (1) {
		printf("Menu\n");
		printf("1. Insert First\n");
		printf("2. Insert Last\n");
		printf("3. Delete First\n");
		printf("4. Delete Last\n");
		printf("5. Print List\n");
		printf("0. Exit\n");
		printf("Enter the menu: ");
		scanf_s("%d", &choice);

		if (choice == 1) {
			printf("Input a number: ");
			scanf_s("%d", &num);
			insert_first(&head, num);
		}
		else if (choice == 2) {
			printf("Input a number: ");
			scanf_s("%d", &num);
			insert_last(&head, num);
		}
		else if (choice == 3) {
			delete_first(&head);
			printf("First node has been deleted.");
		}
		else if (choice == 4) {
			delete_last(&head);
			printf("Last node has been deleted.");
		}
		else if (choice == 5) {
			print_list(&head);
		}
		else if (choice == 0) {
			printf("Exit the program.\n");
			break;
		}
		else {
			printf("Invalid Menu. Please select again. \n");
		}
	}
	return 0;
}