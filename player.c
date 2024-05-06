#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char element[100];
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

DListNode* current;

void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}


void print_dlist(DListNode* phead, DListNode* phead2)
{
	DListNode* p, *q;
	q = phead2->rlink;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		
		
		if (p == current)
			printf("<-| #%s, %s# |-> ", p->data, q->data);
		else
			printf("<-| %s, %s |-> ", p->data, q->data);
		if (q != phead2)
		{
			q = q->rlink;
		}
	
	}
	printf("\n");
}

void dinsert(DListNode* before, element data)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	strcpy(newnode->data, data);
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

void ddelete(DListNode* head, DListNode* removed)
{
	if (removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}


int main(void)
{
	char ch;
	DListNode* head1 = (DListNode*)malloc(sizeof(DListNode));
	DListNode* head2 = (DListNode*)malloc(sizeof(DListNode));
	init(head1);
	init(head2);

	dinsert(head1, "parachute");
	dinsert(head1, "ANGOSTURA");
	dinsert(head1, "calico");
	dinsert(head1, "up to me");
	dinsert(head1, "golden hour");
	dinsert(head2, "John K");
	dinsert(head2, "keshi");
	dinsert(head2, "dprian");
	dinsert(head2, "LANY");
	dinsert(head2, "JVKE");


	current = head1->rlink;
	print_dlist(head1, head2);

	do {
		printf("\n명령어를 입력하시오(<, >, q): ");
		ch = getchar();
		if (ch == '<') {
			current = current->llink;
			if (current == head1)
				current = current->llink;
		}
		else if (ch == '>') {
			current = current->rlink;
			if (current == head1)
				current = current->rlink;
		}
		print_dlist(head1, head2);
		getchar();
	} while (ch != 'q');
	free(head1);
	return 0;
}