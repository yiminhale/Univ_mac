#ifndef STACK_ARRAY_H//clion의 중복 헤더파일 사용 필터링: 이 헤더파일이 정의되지 않았다면
#define STACK_ARRAY_H//clion의 중복 헤더파일 사용 필터링: 이 헤더파일을 정의한다.
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
///////////////////////////////////////////////////////////
typedef int Element;
typedef struct
{
	Element *stack;//int *stack 과 동일
	int size;
	int top;
}Stack;
///////////////////////////////////////////////////////////
static inline Stack *CreateStack(int size)//inline: Clion의 헤더파일 여럿 사용시 발생하는 문제 해결위한 조치
{
	Stack *pStack = (Stack *)calloc(1,sizeof(Stack));//stack, size, top 3개 를 저장할 메모리 할당.
	if (pStack==NULL)//생성되지 않았을 경우
	{
		return NULL;//NULL 반환
	}
	pStack->stack=(Element*)calloc(size,sizeof(Element));//stack 부분에 우리가 생성할 Stack에 해당하는 크기의 메모리 할당 후 주소 저장
	if (pStack->stack==NULL)//생성되지 않았을 경우
	{
		free(pStack);//pStack 해제 후
		return NULL;//NULL 반환
	}

	pStack->size=size;//스택 크기
	pStack->top=-1;//기준점 설정
	return pStack;
}

static inline void Push(Stack *pStack,int item)// 스택이 다 찼다면, 에러. 아니라면, item을 스택의 top에 삽입
{
	if (pStack->top==pStack->size-1)//stack이 다 찼다면,
	{
		printf("Stack is Full\n");
	}
	pStack->stack[pStack->top+1]=item;//index로 인해 -1된 top에 1을 더한 부분에 item 저장
	pStack->top++;//top 증가
}

static inline Element Pop(Stack *pStack)
{
	if (pStack->top==-1)
	{
		printf("Stack is Empty\n");
	}
	Element rtn_value=pStack->stack[pStack->top];//현재 top에 있는 값 rtn_value에 저장
	pStack->top--;//top 하나 감소.
	return rtn_value;//해당 값 반환
}

static inline Element Top(Stack *pStack)
{
	Element rtn_value=pStack->stack[pStack->top];//현재 top 에 있는 값 저장
	return rtn_value;//값 반환
}

static inline void DestoryStack(Stack *pStack)
{
	free(pStack->stack);
	free(pStack);
}

static inline bool IsFullStack(Stack *pStack)
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

static inline bool IsEmptyStack(Stack *pStack)
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

static inline int CountStackItem(Stack *pStack)
{
	int rtn_value = pStack->top+1;
	return rtn_value;
}

static inline void ClearStack(Stack *pStack)
{
	pStack->top=-1;
}
///////////////////////////////////////////////////////////
#endif // STACK_ARRAY_H//정의 종료