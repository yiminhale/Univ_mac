#ifndef ASSG_8_AD_MATRIX3_H
#define ASSG_8_AD_MATRIX3_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//undirected, weighted graph

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
	//여기서는 이어지지 않았다면 1000으로 부여해야 함.
	int* ifnt = (int*)calloc(1,sizeof(int));
	*ifnt=1000;
	for (int i=1;i<64;i++)
	{
		for (int t = 1;t<64;t++)
		{
			pGraph_mtx->array[i][t]=ifnt;
		}
	}
	//여기까지 이 행렬 특징 추가
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

static inline void AddEdge_mtx(Graph_mtx* pGraph_mtx,void* pstart,void* pend,int weight)//A B
{
	for (int i=1;i<=pGraph_mtx->count;i++)
	{
		if (*(char*)pGraph_mtx->array[i][0]==*(char*)pstart)//행 문자가 일치한다면
		{
			for (int t=1;t<= pGraph_mtx->count;t++)
			{
				if (*(char*)pGraph_mtx->array[0][t]==*(char*)pend)//열 문자가 일치한다면
				{
					int* x=(int*)calloc(1,sizeof(int));
					*x=weight;//가중치 반영
					pGraph_mtx->array[i][t]=x;
					pGraph_mtx->array[t][i]=x;//undirec이므로.
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
					free(pGraph_mtx->array[i][t]);
					free(pGraph_mtx->array[t][i]);
					pGraph_mtx->array[i][t]=NULL;
					pGraph_mtx->array[t][i]=NULL;
					break;
				}
			}
			break;
		}
	}
}
#endif //ASSG_8_AD_MATRIX3_H