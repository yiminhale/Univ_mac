#ifndef DATA_STRUCTURES_STACK_LINK_H
#define DATA_STRUCTURES_STACK_LINK_H
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
///////////////////////////////////////////////////////////
typedef int Element;
typedef struct tStackNode//노드 부분
{
	Element data;//데이터 부분
	struct tStackNode *next;//따라가면 이 구조가 나오는 포인터
}StackNode;

typedef struct //헤드 부분
{
	Element count;//몇개 존재하는지 카운트
	StackNode *Poi;//따라가면 스택노드가 나오는 포인터.
	int size;
}Stack;
///////////////////////////////////////////////////////////
static inline Stack *CreateStack(int size){
	Stack *pStack =(Stack*) calloc(1,sizeof(Stack));
	if (pStack==NULL)
	{
		return NULL;
	}
	pStack->count=0;
	pStack->Poi=NULL;//처음엔 아무것도 안가르킴
	pStack->size=size;
	return pStack;
}

static inline void Push(Stack *pStack,int item)//스택이 다 차지 않았다면, item에 해당하는 data를 추가해라.
{
	if (pStack->count==pStack->size)//조건 확인
	{
		printf("Stack is Full!\n");//반응
	}
	else
	{
		StackNode *newNode=(StackNode*)calloc(1,sizeof(StackNode));
		newNode->data=item;//데이터 추가
		pStack->count++;//카운트 늘려주기
		newNode->next=pStack->Poi;//Poi가 가리키고 있는 애한테 연결
		pStack->Poi=newNode;//Poi가 자신을 가리키도록 설정.
	}
}

static inline Element Pop(Stack *pStack)
{
	if (pStack->count==0)//스택이 비어 있다면
	{
		printf("Stack is Empty!\n");//출력
		return 0;
	}
	else
	{
		Element rtn_value = pStack->Poi->data;//data 저장 변수 선언
		pStack->count--;//카운트 감소
		StackNode *temp_Poi = pStack->Poi;//pop대상 주소 저장
		pStack->Poi=pStack->Poi->next;//Poi의 지칭 대상 변경
		free(temp_Poi);//pop대상 해제
		return rtn_value;
	}
}

static inline Element Top(Stack *pStack)
{
	return pStack->Poi->data;//조회만
}

static inline void DestroyStack(Stack *pStack)//모든 스택 파괴
{
	for (int i=pStack->count;i;i--)//반복문으로 pop 전부 한 후 제거.
	{
		Pop(pStack);//free용도.
	}
	//free(pStack->Poi);//이러면 하나만 파괴되는데?
	free(pStack);//마지막은 얘 파괴 맞음.
}

static inline bool IsFullStack(Stack *pStack)
{
	if (pStack->count==pStack->size)//현재 크기==전체 크기//
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
	if (pStack->count==0)
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
	return pStack->count;
}

static inline void ClearStack(Stack *pStack)
{
	for (int i=pStack->count;i;i--)//반복문으로 pop 전부 한 후 제거.
	{
		Pop(pStack);//free용도.
	}
}
#endif //DATA_STRUCTURES_STACK_LINK_H