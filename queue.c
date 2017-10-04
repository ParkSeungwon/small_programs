#include<stdio.h>
#define SIZE 6
typedef int element ;
typedef struct Queue
{
	element data[SIZE];
	int front, rear;
} Queue;

int is_full(Queue* q) {
	return (q->rear + 1) % SIZE == q->front;
}

void push_back(Queue* q, element n) {
	if(!is_full(q)) {
		q->data[q->rear++] = n;
		q->rear %= SIZE;
	}
}

int is_empty(Queue* q) {
	return q->rear == q->front;
}

element pop(Queue* q) {
	if(!is_empty(q)) {
		element tmp = q->data[q->front++];
		q->front %= SIZE;
		return tmp;
	}
}

void show(Queue* q) {
	for(int i = q->front; i != q->rear; i = ++i%SIZE) printf("%d ", q->data[i]);
}

int main()
{
	Queue q;
	q.front = 0;
	q.rear = 0;
	push_back(&q, 3);
	push_back(&q, 3);
	push_back(&q, 3);
	push_back(&q, 3);
	push_back(&q, 3);
	push_back(&q, 3);
	push_back(&q, 3);
	pop(&q);
	show(&q);
}
