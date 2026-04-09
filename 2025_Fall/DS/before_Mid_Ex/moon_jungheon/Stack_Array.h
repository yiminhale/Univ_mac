#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *stack;
	int size;
	int top;
}Stack;

Stack *CreateStack(int size){
	Stack* pstack = (Stack*)malloc(sizeof(Stack));
	if (pstack == NULL) {
		return NULL;
	}
	pstack->stack = (int*)malloc(size * sizeof(int));
	if (pstack->stack == NULL){
		free(pstack);
		return NULL;
	}
	pstack->size = size;
	pstack->top = -1;

	return pstack;
}

void Push(Stack *pstack, int input) {
	if (pstack->top == pstack->size - 1){
		printf("Stack is full. error.\n");
		return;
	}
	pstack->stack[++pstack->top] = input;
}

int Pop(Stack *pstack) {
	if (pstack->top < 0) {
		printf("Stack is empty. error.\n");
		return -1;
	}
	return pstack->stack[pstack->top--];
}

int Top(Stack* pstack) {
	if (pstack->top < 0) {
		printf("Stack is empty. error.\n");
		return -1;
	}
	return pstack->stack[pstack->top];
}

void DestroyStack(Stack* pstack) {
	if (pstack->size > 0) {
		free(pstack->stack);
	}
	free(pstack);
}

int IsFullStack(Stack* pstack) {
	if (pstack->top == pstack->size - 1) {
		return 1;
	}
	else return 0;
}

int IsEmptyStack(Stack* pstack) {
	if (pstack->top < 0) {
		return 1;
	}
	else return 0;
}

int CountStackItem(Stack* pstack) {
	return pstack->top + 1;
}

void ClearStack(Stack* pstack) {
	pstack->top = -1;
}