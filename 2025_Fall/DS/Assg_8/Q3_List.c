#include "Ad_List3.h"

static inline void Show(Graph_list* pGraph_list);
static inline Graph_list* Ad_List(char* filename);
static inline void MST(Graph_list* pGraph_list);
static inline void Dij(Graph_list* pGraph_list);
static inline void Destroy_list(Graph_list* pGraph_list);

int main ()
{
	printf("File name of a graph : ");
	char filename[128];//입력용 변수 선언
	scanf("%s",filename);//파일명 입력 받기
	Graph_list* pGraph_list=Ad_List(filename);//그래프 인접 리스트로 표현 및 포인터 반환
	if (pGraph_list==NULL)
	{
		printf("sth wrong!\n");
		return 0;
	}
	Show(pGraph_list);
	printf("\n");
	MST(pGraph_list);
	printf("\n");
	Dij(pGraph_list);
	printf("\n");
	Destroy_list(pGraph_list);
	return 0;
}

static inline Graph_list* Ad_List(char* filename)
{
	FILE* fp=fopen(filename,"r");
	if (!fp)
	{
		printf("file not exit\n");;
		return NULL;
	}
	char line[256];//줄별로 읽으니 선언
	Graph_list* pGraph_list=CreateGraph_list();//일단 포인터 생성
	while (fgets(line,sizeof(line),fp)!=NULL)//끝나면 다음 줄로 자동 전환.
	{
		void* add1=NULL;
		void* add2=NULL;
		/*
		Vtx_list* temp1=pGraph_list->first;//순회용 vtx 선언
		while (temp1!=NULL && *(char*)(temp1->data)!=*(char*)line)//line의 첫 문자가 첫 번째 vtx의 내용이 아니라면 반복하라.
		{
			temp1=temp1->pNextVtx;//다음 칸으로 이동
		}//line의 첫 문자가 vtx에 있다면 그것을 가리킬 것이고, 없다면 NULL을 가리킴.
		if (temp1==NULL)//line의 첫 문자가 그래프에 없다면
		{
			char* pch1=(char*)calloc(1,sizeof(char));
			*pch1=line[0];
			add1=pch1;
			InsertVtx(pGraph_list,pch1);
		}//line의 첫 번째 문자 vtx 추가 완료
		else//line의 첫 문자가 그래프에 이미 있다면
		{
			add1=temp1->data;//해당 Vtx의 데이터 주소를 복사. 추후 엣지 이을 때 활용.
		}

		if (strlen(line)<3)
		{
			continue;
		}//하나의 입력밖에 없다면 뒷 부분 생략

		Vtx_list* temp2=pGraph_list->first;
		while (temp2!=NULL && *(char*)(temp2)->data !=*(char*)(line+2))
		{
			temp2=temp2->pNextVtx;
		}
		if (temp2==NULL)
		{
			char* pch2=(char*)calloc(1,sizeof(char));
			*pch2=line[2];
			add2=pch2;
			InsertVtx(pGraph_list,pch2);
		}
		else
		{
			add2=temp2->data;
		}
		*///strtok로 활용하기 이전 구형 버전.
		char* start=strtok(line," \n");
		char* end=strtok(NULL, " \n");
		char* weight = strtok(NULL, " \n");
		if (end==NULL)
		{
			char* pchr1=(char*)calloc(1,sizeof(char));
			*pchr1=*start;
			InsertVtx(pGraph_list,pchr1);
		}//첫 문자만 있는 경우
		else
		{
			Vtx_list* temp1=pGraph_list->first;
			while (temp1!=NULL && (*(char*)temp1->data!=*start))
			{
				temp1=temp1->pNextVtx;
			}
			if (temp1==NULL)
			{
				char* pchr1=(char*)calloc(1,sizeof(char));
				*pchr1=*start;
				add1=pchr1;
				InsertVtx(pGraph_list,add1);
			}//첫 문자가 없다면--> 노드에 추가 및 add1 할당
			//있다면?
			else
			{
				add1=temp1->data;
			}
			Vtx_list* temp2=pGraph_list->first;
			while (temp2!=NULL&&(*(char*)temp2->data!=*end))
			{
				temp2=temp2->pNextVtx;
			}
			if (temp2==NULL)
			{
				char* pchr2=(char*)calloc(1,sizeof(char*));
				*pchr2=*end;
				add2=pchr2;
				InsertVtx(pGraph_list,add2);
			}//두 번째 문자가 없다면 --> 노드에 추가
			//있다면
			else
			{
				add2=temp2->data;
			}
			//가중치 가공
			int w= atoi(weight);
			//연결
			AddEdge_list(pGraph_list,add1,add2,w);
			AddEdge_list(pGraph_list,add2,add1,w);//undirec이므로 양방향 연결해줘야 함.
		}//일반적인 경우
	}
	fclose(fp);//파일 닫기
	return pGraph_list;//포인터 계속 써야 하니까
}
static inline void Show(Graph_list* pGraph_list)
{
	printf("The Graph is : \n");
	if (pGraph_list==NULL)
	{
		printf("smt wrong\n");
		return ;
	}
	Vtx_list* pVtx=pGraph_list->first;
	while (pVtx)
	{
		printf("%c : ",*(char*)pVtx->data);
		Arc_list* pArc=pVtx->pArc;
		while (pArc)
		{
			printf("%c (%d) ",*(char*)pArc->destination->data,pArc->weight);
			pArc=pArc->pNextArc;
		}
		pVtx=pVtx->pNextVtx;
		printf("\n");
	}
}
static inline void MST(Graph_list* pGraph_list)//Prim
{
	printf("Minimum Spanning Tree : \n");
	int count=0;Vtx_list* pVtx=pGraph_list->first;
	while (pVtx!=NULL)
	{
		++count;//node 총 몇개인지 세기
		pVtx=pVtx->pNextVtx;
	}
	Vtx_list* T[2][256]={0};//어디서 어디로 가는지 엣지 의미
	Vtx_list* TV[256]={0};//노드 의미.
	int wgt[256]={0};
	pVtx=pGraph_list->first;//재지정
	TV[0]=pGraph_list->first;//일단 첫부분은 무조건 집어넣어주기.
//이것도. 	T[0][0]=pGraph_list->first;//첫 부분은 A로 넣어줘야지
	int vstd[256]={0};//vstd['A']=1 or 0으로 사용
	vstd[*(char*)pVtx->data]++;//vstd['A']++;

	/*논리 구성
	 *1. 후보 구성. 시작시에는 B6, C3이 후보지만, 점점 늘어날수록 후보의 갯수도 늘어나고 그 후보가 어느 노드에서 이어져 있는지도 판단해야 함.
	 *		후보 구성 시에는 visited를 확인하여 이미 방문한 노드는 후보에 삽입되면 안되기에 이를 조건문으로 확인할 것.
	 *2. 후보에서 제일 작은 경로 채택.
	 */


	for (int i = 0;i<count-1;i++)//01234 : 5개
	{
		int min_w=9999;//최종 후보의 가중치
		Arc_list* pcdd=pVtx->pArc;//후보를 가리키는 아크 포인터//시작은 A 바로 옆 아크부터.
		Arc_list* pArc=pcdd;//순회용
		int order=0;
		while (order<i+1)//첫 번째는 한번만, 두번째는 노드가 2개니까 2번만.
		{
			//조건 확인
			if (vstd[*(char*)pArc->destination->data]!=0)//이미 방문 했다면--> 다음 아크로 이동
			{
				//다음 아크 있다면
				if (pArc->pNextArc!=NULL)
				{
					pArc=pArc->pNextArc;
				}
				//만약 다음 아크 없다면
				else
				{
					if (TV[order+1]!=NULL)//처음일 경우 문제 발생
					{
						pArc=TV[order+1]->pArc;//다음 Vtx의 아크로 이동
					}
					order++;//한번 다음 Vtx로 이동했으니 증가
				}
			}
			else//방문하지 않았다면--> 갱신 여부 검토
			{
				//갱신 조건
				if (pArc->weight<min_w)
				{
					pcdd=pArc;//후보 설정
					min_w=pcdd->weight;
					//일단 등록( 어차피 반복되면서 갱신 )
					wgt[i]=min_w;//가중치 등록
					T[0][i]=TV[order];//해당 pcdd가 어느 vtx에서 나왔는지 등록해야 하는데...
					T[1][i]=pcdd->destination;
					TV[i+1]=pcdd->destination;//TV 다음 자리에 후보 삽입. 수정 가능.// 첫자리는 A 들어가 있으니까.
				}
				//다음 아크로 이동
				if (pArc->pNextArc!=NULL)
				{
					pArc=pArc->pNextArc;
				}
				//만약 다음 아크 없다면
				else
				{
					if (TV[order+1]!=NULL)//처음일 경우 문제 발생
					{
						pArc=TV[order+1]->pArc;//다음 Vtx의 아크로 이동
					}
					order++;//한번 다음 Vtx로 이동했으니 증가
				}
			}
		}//다음 Vtx가 없고 다음 Arc도 없다면 반복 중단.
		vstd[*(char*)pcdd->destination->data]++;
	}//끝나지 않았다면 반복-->끝==T[][count-2]까지 채워졌을 때.

	//출력하면 끝
	for (int i = 0;i<count-1;i++)
	{
		printf("%c %c (%d)\n",*(char*)T[0][i]->data,*(char*)T[1][i]->data,wgt[i]);
	}
}
static inline void Dij(Graph_list* pGraph_list)//Dijkstra
{
	printf("Shortest Path from %c : \n",*(char*)pGraph_list->first->data);
	int count=0;Vtx_list* pVtx=pGraph_list->first;
	while (pVtx!=NULL)
	{
		++count;//node 총 몇개인지 세기
		pVtx=pVtx->pNextVtx;
	}

	int d[256]={0};//최소경로값 저장용 배열//각 char 인덱스에 경로값 저장.
	for (int i = 0;i<256;i++)
	{
		d[i]=1000;//초기화
	}
	d[*(char*)pGraph_list->first->data]=0;
	int vstd[256]={0};

	for (int i=1;i<count;i++)//1~5 5번 반복: 노드 갯수 - 1 번 반복해야 함.
	{
		//구성
		//미방문 노드 중 d값 최소인 노드 찾기
		Vtx_list* sltd = NULL;
		int mdist=1001;
		pVtx = pGraph_list->first;
		while (pVtx != NULL)
		{
			if (vstd[*(char*)pVtx->data]==0 && d[*(char*)pVtx->data]<mdist)
			{
				mdist = d[*(char*)pVtx->data];
				sltd = pVtx;
			}
			pVtx = pVtx->pNextVtx;
		}

		//선택된 노드의 누적 거리
		int dist = d[*(char*)sltd->data];

		//선택된 노드의 아크들 업뎃
		Arc_list* pArc = sltd->pArc;
		while (pArc != NULL)
		{
			int new_dist = dist + pArc->weight;
			if (new_dist < d[*(char*)pArc->destination->data])
			{
				d[*(char*)pArc->destination->data] = new_dist;
			}
			pArc = pArc->pNextArc;
		}

		//방문 표시
		vstd[*(char*)sltd->data]++;

		//출력
		pVtx=pGraph_list->first->pNextVtx;
		for (int t=1;t<count;t++)//1~5: 5번 반복
		{
			printf("%c %c : %d\n",*(char*)pGraph_list->first->data,*(char*)pVtx->data,d[*(char*)pVtx->data]);
			pVtx=pVtx->pNextVtx;
		}
		printf("\n");
	}
	//최종 출력
	pVtx=pGraph_list->first->pNextVtx;
	for (int i=1;i<count;i++)//1~5: 5번 반복
	{
		printf("%c %c : %d\n",*(char*)pGraph_list->first->data,*(char*)pVtx->data,d[*(char*)pVtx->data]);
		pVtx=pVtx->pNextVtx;
	}
}

static inline void Destroy_list(Graph_list* pGraph_list)
{
	if (pGraph_list==NULL)
	{
		return ;
	}

	Vtx_list* pVtx=pGraph_list->first;
	while (pVtx!=NULL)
	{
		Arc_list* pArc=pVtx->pArc;
		while (pArc!=NULL)
		{
			Arc_list* temp=pArc;
			pArc=pArc->pNextArc;
			free(temp);
		}
		free(pVtx->data);
		Vtx_list* temp1=pVtx;
		pVtx=pVtx->pNextVtx;
		free(temp1);
	}
	free(pGraph_list);
}