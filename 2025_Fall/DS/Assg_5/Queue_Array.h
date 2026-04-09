#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//////////////////////////////////////////////////////
typedef char Data[1024];
typedef struct
{
	int front;//프론트 저장 변수
	int rear;//리어 저장 변수
	int size;//크기 저장
	int count;//카운트... 필요한지?
	Data *queue;//찾아가면 큐가 나오는.
}Circular_Queue;

/////////////////////////////////////////함수 구현
static inline Circular_Queue *CreateQueue(int size)
{
	Circular_Queue *pC_Queue=(Circular_Queue*)calloc(1,sizeof(Circular_Queue));
	if (pC_Queue==NULL)
	{
		return NULL;
	}
	pC_Queue->size=size;//크기 초기화
	pC_Queue->front=0;//프론트 초기화
	pC_Queue->rear=0;//리어 초기화
	pC_Queue->count=0;//카운트 초기화
	pC_Queue->queue=(Data*)calloc(size,sizeof(Data));//큐 할당할 메모리 생성.
	if (pC_Queue->queue==NULL)//생성되었는지 확인
	{
		return NULL;
	}
	return pC_Queue;
}

static inline void Enqueue(Circular_Queue *pC_Queue,Data x)
{
	//조건: 큐가 다 차지 않았다면
	if ((pC_Queue->rear+1)%(pC_Queue->size)==pC_Queue->front)//Full 조건: rear+1 %size == front
	{
		printf("Queue is Full!\n");
		return ;
	}
	strcpy(pC_Queue->queue[(pC_Queue->rear+1)%pC_Queue->size],x);//rear 다음칸에 입력하기
	pC_Queue->rear=(pC_Queue->rear+1)%pC_Queue->size;//리어를 조정
	pC_Queue->count++;//카운트 하나 올리기
}

static inline Data *Dequeue(Circular_Queue *pC_Queue)
{
	//조건: 큐가 비어있지 않다면
	if (pC_Queue->front == pC_Queue->rear)//empty 조건: rear == front
	{
		printf("Queue is Empty!\n");
		return NULL;
	}
	//front에 해당하는 값을 임시 변수에 저장하고
	Data *rtn_value = (Data*)calloc(1,sizeof(Data));
	strcpy(*rtn_value,pC_Queue->queue[(pC_Queue->front+1)%pC_Queue->size]);//front에 해당하는 내용물 저장
	//front를 하나 올리며
	pC_Queue->front=(pC_Queue->front+1)%pC_Queue->size;
	pC_Queue->count--;//카운트 하나 줄이기
	//임시변수에 해당하는 것을 삭제해야 함.
	strcpy(pC_Queue->queue[pC_Queue->front],"");//\0으로 설정
	return rtn_value;
}//반드시 free 해야 함.

static inline Data *QueueFront(Circular_Queue *pC_Queue)
{
	Data *rtn_value=(Data*)calloc(1,sizeof(Data));
	strcpy(*rtn_value,pC_Queue->queue[(pC_Queue->front+1)%pC_Queue->size]);
	return rtn_value;
}//반드시 free 해야 함.

static inline Data *QueueRear(Circular_Queue *pC_Queue)
{
	Data *rtn_value=(Data*)calloc(1,sizeof(Data));
	strcpy(*rtn_value,pC_Queue->queue[(pC_Queue->rear)%pC_Queue->size]);
	return rtn_value;
}//반드시 free 해야 함.

#endif // QUEUE_ARRAY_H