#ifndef BEFORE_MID_EX_CUSTOMER_LINK_H
#define BEFORE_MID_EX_CUSTOMER_LINK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

테이블의 손님들은 문자열에 각각의 숫자를 통해 문자열로 입력되어 있음.
e.g. input: 231
	저장: '2' '3' '1' '\0'

문자열은 배열이므로, stack에 해당하는 부분은 포인터를 이용한 배열로 처리해보자
 */

typedef int Element;

typedef struct Head
{
	int top;//지칭하는 위치
	int size;//크기
	Element *stack;
}Head;

static inline Head *CreateStack(int size)
{
	Head *pStack = (Head*)calloc(1,sizeof(Head));
	pStack->top=0;
	pStack->size=size;
	pStack->stack=(Element*)calloc(size,sizeof(Element));
	return pStack;
}

static inline void Push(Head *pStack,Element x)
{
	if (pStack->top == pStack->size)
	{
		printf("Stack is Full\n");
	}
	else
	{
		pStack->stack[pStack->top]=x;
		pStack->top++;
	}
}

static inline Element Pop(Head *pStack)
{
	if (pStack->top == 0)
	{
		printf("Stack is empty!\n");
		return 0;
	}
	else
	{
		Element temp = pStack->stack[pStack->top-1];//top보다 하나 아래 가리켜야 함.
		pStack->top--;//숫자 하나 감소
		return temp;
	}
}

static inline void DestroyStack(Head *pStack)
{
	free(pStack->stack);
	free(pStack);
}





#endif //BEFORE_MID_EX_CUSTOMER_LINK_H