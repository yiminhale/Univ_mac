#ifndef LINK_H
#define LINK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int Element;

typedef int Boolean;//���̸� 1��ȯ, �����̸� 0��ȯ

typedef struct QNode {
	Element data;
	struct QNode* next;
}QNode;

typedef struct SNode {
	Element data;
	struct SNode* next;
}SNode;

typedef struct Queue {
	int count;
	QNode* pfront;
	QNode* prear;
	int size;
}Queue;

typedef struct Stack {
	int size;
	int count;
	SNode* top;
}Stack;

///////////////////////////////////////////////STACK!!!!
static inline Stack *CreateStack(int size) {
	Stack* pStack = (Stack*)calloc(1, sizeof(Stack));
	if (pStack == NULL) {
		return NULL;
	}
	pStack->count = 0;
	pStack->top = NULL;
	pStack->size = size;
	return pStack;
}

static inline void Push(Stack *pStack,Element data) {
	if (pStack->count==pStack->size) {
		printf("Stack is Full!\n");
		return;
	}
	if (pStack->count == 0) {
		SNode* pSNode = (SNode*)calloc(1, sizeof(SNode));
		pSNode->data = data;
		pSNode->next = NULL;

		pStack->top = pSNode;//�ϳ��� ž�� ����
		pStack->count++;
	}
	else {
		SNode* pSNode = (SNode*)calloc(1, sizeof(SNode));
		pSNode->data = data;
		pSNode->next = pStack->top;

		pStack->top = pSNode;
		pStack->count++;
	}
}

static inline Element Pop(Stack* pStack) {
	if (pStack->count==0) {
		printf("Stack is Empty!\n");
		return -1;
	}
	Element rtn_value = pStack->top->data;
	SNode* temp = pStack->top;
	pStack->top=pStack->top->next;
	free(temp);
	pStack->count--;
	return rtn_value;
}

static inline Element Top(Stack* pStack) {
	Element rtn_value = pStack->top->data;
	return rtn_value;
}

static inline void DestroyStack(Stack* pStack) {
	while (pStack->count!=0) {
		Pop(pStack);
	}
	free(pStack);
}

static inline Boolean IsFullStack(Stack *pStack) {
	if (pStack->count==pStack->size) {
		return 1;
	}
	else {
		return 0;
	}
}

static inline Boolean IsEmptyStack(Stack* pStack) {
	if (pStack->count == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

static inline int CountStackItem(Stack* pStack) {
	return pStack->count;
}

static inline void ClearStack(Stack* pStack) {
	while (pStack->count != 0) {
		Pop(pStack);
	}
}

///////////////////////////////////////////////QUEUE!!!!!
static inline Queue *Q_Create(int size) {
	Queue* pQueue = (Queue*)calloc(1, sizeof(Queue));
	if (pQueue == NULL) {
		return NULL;
	}
	pQueue->count = 0;
	pQueue->pfront = NULL;
	pQueue->prear = NULL;
	pQueue->size = size;
	return pQueue;
}

static inline Boolean Q_isEmpty(Queue* pQueue) {
	if (pQueue->count==0) {
		return 1;
	}
	else {
		return 0;
	}
}

static inline Boolean Q_isFull(Queue* pQueue) {
	if (pQueue->count ==pQueue->size) {
		return 1;
	}
	else {
		return 0;
	}
}

static inline Boolean Q_Enqueue(Queue* pQueue, Element data) {
	if (pQueue->count==pQueue->size) {
		printf("Queue is Full!\n");
		return 0;
	}
	if (pQueue->count == 0) {
		QNode* pQNode = (QNode*)calloc(1, sizeof(QNode));
		pQNode->data = data;
		pQNode->next = NULL;

		pQueue->pfront = pQueue->prear = pQNode;
		pQueue->count++;
		return 1;
	}
	else {
		QNode* pQNode = (QNode*)calloc(1, sizeof(QNode));
		pQNode->data = data;
		pQNode->next = NULL;

		pQueue->prear->next = pQNode;
		pQueue->prear = pQNode;
		pQueue->count++;
		return 1;
	}
}

static inline Element Q_Dequeue(Queue* pQueue) {
	if (pQueue->count==0) {
		printf("Queue is Empty!\n");
		return -1;
	}
	Element rtn_value=pQueue->pfront->data;
	QNode* temp = pQueue->pfront;
	pQueue->pfront = pQueue->pfront->next;
	free(temp);
	pQueue->count--;
	return rtn_value;
}

static inline int Q_Destroy(Queue *pQueue) {
	if (pQueue == NULL) {
		printf("Wrong!");
		return 0;
	}
	while (pQueue->count != 0) {
		Q_Dequeue(pQueue);
	}
	free(pQueue);
	return 1;//����
}

#endif // LINK_H
