#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;	
	head = p;
	return head;
}


ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;	
	p->link = pre->link;	
	pre->link = p;		
	return head;		
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;	
	head = removed->link;	
	free(removed);		
	return head;		
}

ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;	
	free(removed);		
	return head;		
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}


int main(void)
{
	ListNode* head = NULL;

	for (int i = 0; i < 5; i++) { //1번
		head = insert_first(head, i);
		print_list(head);
	}

	ListNode* pre = NULL; //2번
	pre = head;
	for (int i = 0; i < 2; i++)
	{
		pre = pre->link;
	}
	head = insert(head, pre, 30);
	print_list(head);

	pre = head; //pre 초기화

	for (int i = 0; i < 1; i++) //3번
	{
		pre = pre->link;
	}

	head = delete(head, pre);
	print_list(head);

	for (int i = 0; i < 5; i++) //4번
	{
		head = delete_first(head);
		print_list(head);
	}

	return 0;
}