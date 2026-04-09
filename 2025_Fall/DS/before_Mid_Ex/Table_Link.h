#ifndef BEFORE_MID_EX_TABLE_LINK_H
#define BEFORE_MID_EX_TABLE_LINK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/////////////////////////////////////////
typedef char Data[1024];//각 숫자를 문자열로 받아서, 배열처럼 사용. 정수전환시에는 -'0'사용

typedef struct Queue
{
	Data content;
	struct Queue *next;
}Queue;

typedef struct
{
	Queue *pfront;
	Queue *prear;
	int count;//몇개 있는지 세야지
}FAR;

static inline FAR *CreateQueue()
{
	FAR *pFAR = (FAR*)calloc(1,sizeof(FAR));//FAR 메모리 할당
	if (pFAR == NULL)
	{
		return NULL;
	}
	pFAR->count = 0;
	pFAR->pfront=NULL;
	pFAR->prear=NULL;
	return pFAR;
}

static inline void Enqueue(FAR *pFAR, Data x)
{
	if (pFAR->prear==NULL)//queue가 비어있을 경우
	{
		pFAR->pfront=pFAR->prear=(Queue*)calloc(1,sizeof(Queue));
		pFAR->prear->next=NULL;
		strcpy(pFAR->prear->content,x);
		pFAR->count++;//개수 증가
	}
	else//비어있지 않을 경우
	{
		pFAR->prear->next=(Queue*)calloc(1,sizeof(Queue));//다음 큐 생성 및 메모리 할당
		pFAR->prear=pFAR->prear->next;//순서 조정
		pFAR->prear->next=NULL;//뒤에 가리키는 것 없으니 null
		strcpy(pFAR->prear->content,x);//내용 입력
		pFAR->count++;//개수 증가
	}
}

static inline Data *Dequeue(FAR *pFAR)
{
	if (pFAR->count==0)//비어 있다면
	{
		return NULL;
	}

	Data *rtn_value=(Data*)calloc(1,sizeof(Data));//내용물 저장할 메모리 생성
	strcpy(*rtn_value,pFAR->pfront->content);//내용물 복사

	Queue *temp=pFAR->pfront;
	pFAR->pfront = pFAR->pfront->next;
	if (pFAR->pfront==NULL)//한개 남아있어서 pfront가 널일 경우
	{
		pFAR->prear=NULL;//prear도 널로 만들어야지
	}
	free(temp);
	pFAR->count--;

	return rtn_value;
}//추후 반드시 free해야 함! 메모리를 할당받아서 복사했기 때문.

#endif //BEFORE_MID_EX_TABLE_LINK_H