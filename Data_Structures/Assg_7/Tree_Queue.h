#ifndef ASSG_7_TREE_QUEUE_H
#define ASSG_7_TREE_QUEUE_H

#include "Binary_Tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//breath first traversal을 위해, 트리 구성을 위해 Queue를 사용하고, 그 큐를 구현하는 헤더파일

typedef TreeNode *element;//큐의 원소 타입 지정: 주소를 저장해야 함.

typedef struct QNode
{
	element ads;
	struct QNode *next;
}QNode;

typedef struct Queue
{
	int count;
	QNode *front;
	QNode *rear;
}Queue;

static inline Queue *CreateQueue(TreeNode *pRoot)
{
	Queue *pqueue = (Queue*)calloc(1,sizeof(Queue));
	if (pqueue==NULL)//생성되었는지 확인
	{
		return NULL;
	}
	pqueue->count=1;//하나 만들거니까
	pqueue->front=pqueue->rear=(QNode*)calloc(1,sizeof(QNode));//바로 연결
	pqueue->rear->ads=pRoot;//주소할당
	pqueue->rear->next=NULL;//다음은 없으므로.
	return pqueue;
}

static inline void Enqueue(Queue *pqueue,element data)
{
	QNode *pnode = (QNode*)calloc(1,sizeof(QNode));//새 메모리 공간 할당
	if (pqueue->count==0)
	{
		pnode->ads=data;
		pnode->next=NULL;
		pqueue->front=pqueue->rear=pnode;
		pqueue->count++;
	}
	else
	{
		pqueue->rear->next=pnode;//잇기
		pqueue->rear=pnode;//rear 변경
		pqueue->rear->ads=data;
		pqueue->rear->next=NULL;
		pqueue->count++;
	}
}

static inline element Dequeue(Queue *pqueue)
{
	if (pqueue->count==0)
	{
		return NULL;
	}
	TreeNode *rtn_value = pqueue->front->ads;
	QNode *temp = pqueue->front;//삭제 대상
	pqueue->front=pqueue->front->next;//front 조정 . 마지막일 경우 널됨
	free(temp);//제거
	pqueue->count--;
	return rtn_value;
}

#endif //ASSG_7_TREE_QUEUE_H

