#include "Ad_List.h"
#include "Ad_Matrix.h"

static inline void DFS(Vtx_list* pVtx);
static inline void BFS(Vtx_list* pVtx);
static inline Graph_list* Ad_List(char* filename);
static inline void Show(Graph_list* pGraph_list);
static char output_BFS[64]={0};
static char output_DFS[64]={0};
static inline void Destroy_list(Graph_list* pGraph_list);

int main()
{
	printf("File name of a graph : ");
	char filename[128];//입력용 변수 선언
	scanf("%s",filename);//파일명 입력 받기
	Graph_list* pGraph_list=Ad_List(filename);//그래프 인접 리스트로 표현 및 포인터 반환
	Show(pGraph_list);

	printf("Depth First Traversal : ");
	DFS(pGraph_list->first);//dfs 구성
	printf("%s\n",output_DFS);

	printf("Breadth First Traversal : ");
	BFS(pGraph_list->first);//bfs 구성
	printf("%s\n",output_BFS);
	Destroy_list(pGraph_list);
	return 0;
}

static inline void DFS(Vtx_list* pVtx)//proceed 변수 추가해서 접근해야 하나? 기존으로는 안되는지?
{
	if (strchr(output_DFS,*(char*)pVtx->data)==NULL)//해당 data가 문자열에 현재 없을 경우에만 추가
	{
		char plus[2]={0};
		plus[0]=*(char*)pVtx->data;
		plus[1]='\0';
		strcat(output_DFS,plus);
		strcat(output_DFS," ");
	}
	Arc_list* temp = pVtx->pArc;
	while (temp)
	{
		DFS(temp->destination);
		temp=temp->pNextArc;
	}
}

static inline void BFS(Vtx_list* pVtx)
{
	/*
	if (strchr(output_BFS,*(char*)pVtx->data)==NULL)//해당 data가 문자열에 현재 없을 경우에만 추가
	{
		char plus[2]={0};
		plus[0]=*(char*)pVtx->data;
		plus[1]='\0';
		strcat(output_BFS,plus);
		strcat(output_BFS," ");
	}
	Arc_list* temp = pVtx->pArc;
	while (temp)
	{
		if (strchr(output_BFS,*(char*)temp->destination->data)==NULL)
		{
			char plus[2]={0};
			plus[0]=*(char*)temp->destination->data;
			plus[1]='\0';
			strcat(output_BFS,plus);
			strcat(output_BFS," ");
		}
		temp = temp->pNextArc;
	}
	if (pVtx->pNextVtx)
	{
		BFS(pVtx->pNextVtx);
	}
	*///입력에 따라 BFS 확정 아님.

	//기초
	Vtx_list* Q[64]={0};//큐
	char V[64]={0};//방문 확인용
	int front = 0;
	int rear = 0;
	Q[rear++]=pVtx;//큐에 삽입
	char temp[2]={0};
	temp[0]=*(char*)pVtx->data;
	strcat(V,temp);//A 저장

	while (front<rear)
	{
		//디큐
		temp[0]=*(char*)Q[front++]->data;
		//출력에 삽입
		strcat(output_BFS,temp);
		strcat(output_BFS," ");
		//인큐
		Arc_list* tarc=Q[front-1]->pArc;
		while (tarc!=NULL)
		{
			if (strchr(V,*(char*)tarc->destination->data)==NULL)
			{
				Q[rear++]=tarc->destination;//Q에 인큐
				temp[0]=*(char*)tarc->destination->data;
				strcat(V,temp);
			}
			tarc=tarc->pNextArc;//리젠
		}

	}
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
		char* start=strtok(line," \n");//Q: 현재는 단일 문자만 잘리긴 하는데, 입력이 바뀌면 확신은 없지 않나?
		char* end=strtok(NULL," \n");
		Vtx_list* temp1=pGraph_list->first;//순회용 vtx 선언
		while (temp1!=NULL && *(char*)(temp1->data)!=*(char*)start)//line의 첫 문자가 첫 번째 vtx의 내용이 아니라면 반복하라.
		{
			temp1=temp1->pNextVtx;//다음 칸으로 이동
		}//line의 첫 문자가 vtx에 있다면 그것을 가리킬 것이고, 없다면 NULL을 가리킴.
		if (temp1==NULL)//line의 첫 문자가 그래프에 없다면
		{
			char* pch1=(char*)calloc(1,sizeof(char));
			*pch1=*start;
			add1=pch1;
			InsertVtx(pGraph_list,pch1);
		}//line의 첫 번째 문자 vtx 추가 완료
		else//line의 첫 문자가 그래프에 이미 있다면
		{
			add1=temp1->data;//해당 Vtx의 데이터 주소를 복사. 추후 엣지 이을 때 활용.
		}

		if (end==NULL)
		{
			continue;
		}//하나의 입력밖에 없다면 뒷 부분 생략

		Vtx_list* temp2=pGraph_list->first;
		while (temp2!=NULL && *(char*)(temp2)->data !=*(char*)end)
		{
			temp2=temp2->pNextVtx;
		}
		if (temp2==NULL)
		{
			char* pch2=(char*)calloc(1,sizeof(char));
			*pch2=*end;
			add2=pch2;
			InsertVtx(pGraph_list,pch2);
		}
		else
		{
			add2=temp2->data;
		}

		AddEdge_list(pGraph_list,add1,add2);//연결
	}
	fclose(fp);//파일 닫기
	return pGraph_list;//포인터 계속 써야 하니까
}

static inline void Show(Graph_list* pGraph_list)
{
	if (pGraph_list==NULL)
	{
		printf("smt wrong\n");
		return ;
	}
	printf("The Graph is : \n");
	Vtx_list* pVtx=pGraph_list->first;
	while (pVtx)
	{
		printf("%c : ",*(char*)pVtx->data);
		Arc_list* pArc=pVtx->pArc;
		while (pArc)
		{
			printf("%c ",*(char*)pArc->destination->data);
			pArc=pArc->pNextArc;
		}
		pVtx=pVtx->pNextVtx;
		printf("\n");
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