#ifndef ASSG_4_STACK_ARRAY2_H
#define ASSG_4_STACK_ARRAY2_H
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
///////////////////////////////////////////////////////////
typedef int Element_INT;
typedef struct
{
	Element_INT *stack;//int *stack 과 동일
	int size;
	int top;
}Stack_INT;
///////////////////////////////////////////////////////////
static inline Stack_INT *CreateStack_INT(int size)//inline: Clion의 헤더파일 여럿 사용시 발생하는 문제 해결위한 조치
{
	Stack_INT *pStack = (Stack_INT *)calloc(1,sizeof(Stack));//stack, size, top 3개 를 저장할 메모리 할당.
	if (pStack==NULL)//생성되지 않았을 경우
	{
		return NULL;//NULL 반환
	}
	pStack->stack=(Element_INT*)calloc(size,sizeof(Element));//stack 부분에 우리가 생성할 Stack에 해당하는 크기의 메모리 할당 후 주소 저장
	if (pStack->stack==NULL)//생성되지 않았을 경우
	{
		free(pStack);//pStack 해제 후
		return NULL;//NULL 반환
	}

	pStack->size=size;//스택 크기
	pStack->top=-1;//기준점 설정
	return pStack;
}

static inline void Push_INT(Stack_INT *pStack,int item)// 스택이 다 찼다면, 에러. 아니라면, item을 스택의 top에 삽입
{
	if (pStack->top==pStack->size-1)//stack이 다 찼다면,
	{
		printf("Stack is Full\n");
	}
	pStack->stack[pStack->top+1]=item;//index로 인해 -1된 top에 1을 더한 부분에 item 저장
	pStack->top++;//top 증가
}

static inline Element_INT Pop_INT(Stack_INT *pStack)
{
	if (pStack->top==-1)
	{
		printf("Stack is Empty\n");
	}
	Element_INT rtn_value=pStack->stack[pStack->top];//현재 top에 있는 값 rtn_value에 저장
	pStack->top--;//top 하나 감소.
	return rtn_value;//해당 값 반환
}

static inline Element_INT Top_INT(Stack_INT *pStack)
{
	Element_INT rtn_value=pStack->stack[pStack->top];//현재 top 에 있는 값 저장
	return rtn_value;//값 반환
}

static inline void DestroyStack_INT(Stack_INT *pStack)
{
	free(pStack->stack);
	free(pStack);
}

static inline bool IsFullStack_INT(Stack_INT *pStack)
{
	if (pStack->top==pStack->size-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

static inline bool IsEmptyStack_INT(Stack_INT *pStack)
{
	if (pStack->top==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

static inline int CountStackItem_INT(Stack_INT *pStack)
{
	int rtn_value = pStack->top+1;
	return rtn_value;
}

static inline void ClearStack_INT(Stack_INT *pStack)
{
	pStack->top=-1;
}
///////////////////////////////////////////////////////////
#endif //ASSG_4_STACK_ARRAY2_H