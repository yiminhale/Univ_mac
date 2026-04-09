#ifndef ASSG_8_AD_LINK3_H
#define ASSG_8_AD_LINK3_H

//Undirec, weight 그래프 입력받으므로 이를 기억할 것.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Graph_list
{
	struct Vtx_list* first;
}Graph_list;

typedef struct Vtx_list
{
	struct Arc_list* pArc;
	struct Vtx_list* pNextVtx;
	void* data;
}Vtx_list;

typedef struct Arc_list
{
	struct Vtx_list* destination;
	struct Arc_list* pNextArc;
	int weight;//추가
}Arc_list;

static inline Graph_list* CreateGraph_list()
{
	Graph_list* pGraph_list=(Graph_list*)calloc(1,sizeof(Graph_list));
	if(pGraph_list==NULL)
	{
		return NULL;
	}
	pGraph_list->first=NULL;
	return pGraph_list;
}

static inline void InsertVtx(Graph_list* pGraph_list, void* data)//vtx만 추가하면 됨
{
	Vtx_list* pVtx=(Vtx_list*)calloc(1,sizeof(Vtx_list));
	if (pVtx==NULL)
	{
		return ;
	}
	pVtx->pArc=NULL;
	pVtx->pNextVtx=NULL;
	pVtx->data=data;

	if (pGraph_list->first==NULL)
	{
		pGraph_list->first=pVtx;
	}
	else
	{
		Vtx_list* temp = pGraph_list->first;//first vtx 가리킴.
		while (temp->pNextVtx!=NULL)
		{
			temp=temp->pNextVtx;
		}
		temp->pNextVtx=pVtx;
	}
}

static inline void DeleteVtx(Graph_list* pGraph_list,const void* data)//vtx 제거 + 대상과 연결되어 있는 엣지도 제거
{
	if (pGraph_list->first==NULL)
	{
		printf("Graph is empty!\n");
		return ;
	}//비어 있는지 확인
	Vtx_list** ppVtx=&(pGraph_list->first);
	while ((*ppVtx)->data!=data)
	{
		ppVtx=&((*ppVtx)->pNextVtx);
	}//목표 vtx까지 도착
	if (!*ppVtx)
	{
		return ;
	}//목표가 없을 경우
	Arc_list* tarc=(*ppVtx)->pArc;//첫 번째 아크 지칭
	while (tarc)
	{
		Arc_list* next = tarc->pNextArc;
		free(tarc);
		tarc=next;
	}//Arc 삭제
	Vtx_list* tvtx=*ppVtx;//현재 vtx 가리키는 임시 vtx 선언
	Vtx_list* tra_vtx=pGraph_list->first;//순회 vtx 선언//얘는 포인터로 충분: 어차피 아크를 삭제하고 이어야 하니까.
	while (tra_vtx)
	{
		Arc_list** tra_arc=&(tra_vtx->pArc);//얘는 더블 포인터로 선언. 삭제시 이어야 하기 때문.
		while (*tra_arc)//체크 필요
		{
			if ((*tra_arc)->destination->data==tvtx->data)
			{
				Arc_list* temp=*tra_arc;
				*tra_arc=(*tra_arc)->pNextArc;
				free(temp);
			}//arc가 삭제 대상이라면
			else
			{
				tra_arc=&((*tra_arc)->pNextArc);//check 필요. pNextArc가 널일 경우를 판단하려면 이렇게 접근하는게 맞지 않나? 92번줄도 수정 완료함. 판단 필요.
			}//그 외
		}//arc 가 존재한다면 반복해라.
		tra_vtx=(tra_vtx)->pNextVtx;//next로 이동
	}//tra vtx가 존재한다면, null이 아니라면 반복하라.
	*ppVtx=(*ppVtx)->pNextVtx;//다음 vtx로 연결하고
	free(tvtx);//삭제
}

static inline void AddEdge_list(const Graph_list* pGraph_list,const void* start_data,const void* end_data,int weight)//기존 vtx 순회하면서 엣지 이어줘야 함.
{
	Vtx_list* tstart=pGraph_list->first;
	while (tstart->data!=start_data)
	{
		tstart=tstart->pNextVtx;
	}//start_data의 vtx 주소 찾기

	Vtx_list* tend=pGraph_list->first;
	while (tend->data!=end_data)
	{
		tend=tend->pNextVtx;
	}//end_data의 vtx 주소 찾기

	Arc_list* pArc=(Arc_list*)calloc(1,sizeof(Arc_list));//새로 추가할 아크 생성
	if (pArc==NULL)
	{
		return ;
	}//생성 확인
	pArc->pNextArc=NULL;//끝에 추가하므로 다음은 없음
	pArc->destination=tend;//아크의 desti는 끝을 가리켜야 함.
	pArc->weight=weight;//가중치 추가

	Arc_list* tarc=tstart->pArc;//tarc는 첫 아크
	if (tarc==NULL)//tarc가 존재하지 않는다면:
	{
		tstart->pArc=pArc;
	}
	else//tarc가 존재한다면
	{
		while (tarc->pNextArc!=NULL)
		{
			tarc=tarc->pNextArc;
		}
		tarc->pNextArc=pArc;
	}
}

static inline void DeleteEdge_list(const Graph_list* pGraph_list,const void* start_data,const void* end_data)
{
	Vtx_list* tstart=pGraph_list->first;
	while (tstart->data!=start_data)
	{
		tstart=tstart->pNextVtx;
	}//start_data의 vtx 주소 찾기

	Vtx_list* tend=pGraph_list->first;
	while (tend->data!=end_data)
	{
		tend=tend->pNextVtx;
	}//end_data의 vtx 주소 찾기

	Arc_list** ppArc= &(tstart->pArc);
	while ((*ppArc)->destination!=tend)
	{
		ppArc=&((*ppArc)->pNextArc);//현재 아크의 pNextArc '의 주소' 를 ppArc에 저장.
	}//ppArc는 삭제 목표 아크까지 도착
	Arc_list* temp= *ppArc;//삭제할 아크 주소 copy
	*ppArc=(*ppArc)->pNextArc;//삭제할 아크의 다음 주소를 *ppArc에 저장. 즉, ppArc는 고정
	free(temp);//아크 삭제
}

#endif //ASSG_8_AD_LINK3_H