#ifndef ASSG_8_AD_MATRIX_H
#define ASSG_8_AD_MATRIX_H
//vertex 삭제 구현하지 않아도 됨.
//directed graph 임.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
 *
 ********* 1, 0 이 아니라 NULL, !NULL(여기서는 (void*)1 로 표현) ************
 *
 */
typedef struct Graph_mtx
{
	int size;
	int count;
	void* array[64][64];//첫행과 첫열은 ABCDEF 의 주소여야 함.
}Graph_mtx;

static inline Graph_mtx* CreateMtx()
{
	Graph_mtx* pGraph_mtx= (Graph_mtx*)calloc(1,sizeof(Graph_mtx));
	pGraph_mtx->count=0;
	pGraph_mtx->size=64;
	return pGraph_mtx;
}

static inline void InsertVtx_mtx(Graph_mtx* pGraph_mtx,void* data)//입력 &A, &B ... 로 받아야 함.
{
	if (pGraph_mtx->count>=pGraph_mtx->size)
	{
		printf("Matrix is full\n");
		return ;
	}//공간 있는지 확인
	pGraph_mtx->array[pGraph_mtx->count+1][0]=data;
	pGraph_mtx->array[0][pGraph_mtx->count+1]=data;
	pGraph_mtx->count++;
}

static inline void AddEdge_mtx(Graph_mtx* pGraph_mtx,void* pstart,void* pend)//A B
{
	for (int i=1;i<=pGraph_mtx->count;i++)
	{
		if (*(char*)pGraph_mtx->array[i][0]==*(char*)pstart)//행 문자가 일치한다면
		{
			for (int t=1;t<= pGraph_mtx->count;t++)
			{
				if (*(char*)pGraph_mtx->array[0][t]==*(char*)pend)
				{
					pGraph_mtx->array[i][t]=(void*)1;
					break;
				}
			}
			break;
		}
	}
}

static inline void DeleteEdge_mtx(Graph_mtx* pGraph_mtx,void* pstart,void* pend)
{
	for (int i=1;i<=pGraph_mtx->count;i++)
	{
		if (*(char*)pGraph_mtx->array[i][0]==*(char*)pstart)//행 문자가 일치한다면
		{
			for (int t=1;t<= pGraph_mtx->count;t++)
			{
				if (*(char*)pGraph_mtx->array[0][t]==*(char*)pend)
				{
					pGraph_mtx->array[i][t]=NULL;
					break;
				}
			}
			break;
		}
	}
}
#endif //ASSG_8_AD_MATRIX_H