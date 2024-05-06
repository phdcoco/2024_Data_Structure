#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef struct {
	int student_no;
	char name[MAX_STRING];
	char address[MAX_STRING];
} element;

element stack[MAX_STACK_SIZE];
int top = -1;

int is_empty()
{
	return (top == -1);
}

int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}

void push(element item)
{
	if (is_full()) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else stack[++top] = item;
}

element pop()
{
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top--];
}

element peek()
{
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top];
}



void print_element(element a)
{
	printf("�й� : %d\n", a.student_no);
	printf("�̸� : %s\n", a.name);
	printf("�ּ� : %s\n", a.address);
	printf("=========================\n");
}

int main()
{
	element ie = { 202101968,
					"Seol",
					"Busan" };
	element oe;

	push(ie);
	oe = pop();
	print_element(oe);

	ie = (element) {202101975,
					"Ryu",
					"Daejeon" };

	push(ie);
	oe = pop();
	print_element(oe);

	ie = (element){ 202001897,
				"Kang",
				"Seoul" };

	push(ie);
	oe = pop();
	print_element(oe);

	return 0;
}