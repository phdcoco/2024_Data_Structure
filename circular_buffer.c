#include <stdio.h>
#include <Stdlib.h>

#define CRT_SECURE_NO_WARNINGS
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void error(char* message, int a)
{
	fprintf(stderr, "%s\n", message);
	printf("시도 횟수 : %d", a);
	exit(1);
	
}
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;

}

int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void queue_print(QueueType* q)
{
	printf("QUEUE(front = %d rear = %d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

void enqueue(QueueType* q, element item, element a)
{
	if (is_full(q))
		error("큐가 포화상태입니다.", a);
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q, element a)
{
	if (is_empty(q))
		error("큐가 공백상태입니다.", a);
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element peek(QueueType* q, element a)
{
	if (is_empty(q))
		error("큐가 공백상태입니다.", a);
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int main(void) {
	QueueType queue;
	int element;
	int try = 0;
	init_queue(&queue);
	srand(time(NULL));
	for (int i = 0; i < 100; i++) {
		try += 1;
		if (rand() % 10 == 0) {
			
			enqueue(&queue, rand() % 100, try);
		}
		queue_print(&queue);
		if (rand() % 10 == 0) {
			
			int data = dequeue(&queue, try);
		}
		queue_print(&queue);
	}
	
	return 0;
}