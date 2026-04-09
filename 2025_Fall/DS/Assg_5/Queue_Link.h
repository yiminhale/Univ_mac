#ifndef QUEUE_LINK_H
#define QUEUE_LINK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//////////////////////////////////////////////////////
typedef char Data[1024];//데이터 타입이 char로 사용할 예정이므로.
typedef struct Queue//큐 자체
{
	Data content;//내용
	struct Queue *next;//다음 큐를 가리키는 포인터.
}Queue;
typedef struct//프론트, 리어 구조체
{
	Queue *pfront;//프론트 지시 포인터
	Queue *prear;//리어 지시 포인터
	int count;//큐에 몇개 존재하는지 세는 변수
}FAR;//Front and Rear
/////////////////////////////////////////함수 구현
static inline FAR *CreateQueue()//큐 시작. input: 큐 크기 및 초기 입력값.
{
	////////////////////////////////////////////////FAR 생성
	FAR *pFAR=(FAR*)calloc(1,sizeof(FAR));//프론트 및 리어 생성.
	if (pFAR==NULL)
	{
		return 0;
	}
	pFAR->count=0;//시작 갯수 0이므로 초기화.
	pFAR->pfront=NULL;//아직은 아무런 큐가 없으므로
	pFAR->prear=NULL;//아직은 아무런 큐가 없으므로
	return pFAR;//pFAR 주소 반환
}

static inline void Enqueue(FAR *pFAR,char x[1024])
{
	//////////////일단 큐 하나 생성하고 거기에 값 대입하기
	Queue *pQueue = (Queue*)calloc(1,sizeof(Queue));//새로운 큐 생성 및 주소 할당 at pQueue
	strcpy(pQueue->content,x);//입력값 Queue의 content에 복사해서 대입하기.
	//////////////link 연결
	if (pFAR->pfront==NULL)//처음 생성하는 큐라면
	{
		pFAR->pfront=pQueue;//이 큐를 지정하도록 명령.
		pFAR->prear=pQueue;//이 큐를 지정하도록 명령
		pFAR->pfront->next=NULL;
	}
	else//처음 생성하는 큐가 아니라면
	{
		pFAR->prear->next=pQueue;//rear의 next를 새로운애로 지칭하고
		pFAR->prear=pQueue;//prear를 추가한 큐로 수정해줘야 함.
		pQueue->next=NULL;//지금 추가한 것은 널로.
	}
	pFAR->count++;//카운트 하나 늘려줘야지
}

static inline Data *Dequeue(FAR *pFAR)//dequeue 과정
{
	/////////////////////////////////////비어있는 큐인지 확인
	if (pFAR->count==0)
	{
		printf("Queue is empty!\n");
		return 0;
	}
	/////////////////////////////////////dequeue할 큐의 변수 담기
	Data *rtn_value=(Data*)calloc(1024,sizeof(Data));//반환값 변수 선언
	strcpy(*rtn_value,pFAR->pfront->content);//반환 변수에 반환값 담기
	/////////////////////////////////////순서 조정
	Queue *temp=pFAR->pfront;//free할 대상 저장하는 임시 변수
	pFAR->pfront=pFAR->pfront->next;//pfront 다음대상으로 변경
	/////////////////////////////////////Dequeue대상 제거
	free(temp);//free
	pFAR->count--;//카운트 줄여주기
	/////////////////////////////////////반환값
	return rtn_value;//데이터가 들어있는 메모리 주소를 반환함.
}//반드시 나중에 free로 해제해야 함!

static inline Data *QueueFront(FAR *pFAR)//Front check
{
	Data *rtn_value=(Data*)calloc(1024,sizeof(Data));
	strcpy(*rtn_value,pFAR->pfront->content);
	return rtn_value;
}//반드시 free로 해제할 것.

static inline Data *QueueRear(FAR *pFAR)//Rear check
{
	Data *rtn_value=(Data*)calloc(1024,sizeof(Data));
	strcpy(*rtn_value,pFAR->prear->content);
	return rtn_value;
}//반드시 free로 해제할 것.

#endif // QUEUE_LINK_H