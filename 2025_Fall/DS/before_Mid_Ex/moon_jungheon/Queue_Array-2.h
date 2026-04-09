#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char** queue;
	int size;
	int front, rear;
}Queue;

Queue* CreateQueue(int size) {
	Queue* pQueue = (Queue*)malloc(sizeof(Queue));
	if (pQueue == NULL) {
		return NULL;
	}

	pQueue->queue = (char**)malloc(size * sizeof(char*));
	if (pQueue->queue == NULL) {
		free(pQueue);
		return NULL;
	}
	pQueue->size = size;
	pQueue->front = pQueue->rear = 0;

	return pQueue;
}

void Enqueue(Queue* q, char* item) {
	if (IsFullQueue(q)){
		printf("Queue is full. error.\n");
		return;
	}
	else{
		q->rear = (q->rear + 1) % q->size;
		q->queue[q->rear] = (char*)malloc(strlen(item)+1);
		strcpy(q->queue[q->rear], item);
	}
}

char* Dequeue(Queue* q) {
	if (IsEmptyQueue(q)) {
		printf("Queue is empty. error.\n");
		return NULL;
	}
	else{
		q->front = (q->front + 1) % q->size;
		char* item = q->queue[q->front];
		q->queue[q->front] = NULL;
		return item;
	}
}

int IsFullQueue(Queue* q) {
	if ((q->rear + 1) % q->size == q->front) {
		return 1;
	}
	else
		return 0;
}

int IsEmptyQueue(Queue* q) {
	if (q->front == q->rear) {
		return 1;
	}
	else
		return 0;
}

char* QueueFront(Queue* q) {
	if (IsEmptyQueue(q)) {
		printf("Queue is empty. error.\n");
		return NULL;
	}
	else
		return q->queue[q->front];
}

char* QueueRear(Queue* q) {
	if (IsEmptyQueue(q)) {
		printf("Queue is empty. error.\n");
		return NULL;
	}
	else 
		return q->queue[q->rear];
}

int CountQueueItem(Queue* q) {
	return (q->rear - q->front + q->size) % q->size;
}

void ClearQueue(Queue* q) {
	while (!IsEmptyQueue(q)){
		free(Dequeue(q));
	}
	q->front = q->rear = 0;
}

void DestroyQueue(Queue* q) {
	for (int i = 0; i < q->size; i++) {
		if (q->queue[i] != NULL)
			free(q->queue[i]);
	}
	free(q->queue);
	free(q);
}