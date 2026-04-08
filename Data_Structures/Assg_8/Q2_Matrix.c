#include "Ad_Matrix.h"
//#define debug

static inline void DFS(Graph_mtx* pGraph_mtx,int raw, int col);
static inline void BFS(Graph_mtx* pGraph_mtx);
static inline Graph_mtx* Ad_mtx(const char* filename);
static inline void Show(Graph_mtx* pGraph_mtx);
static char output_BFS[64]={0};
static char output_DFS[64]={0};
static inline void Destroy_Mtx(Graph_mtx* pGraph_mtx);

int main()
{
	printf("File name of a graph : ");
	char filename[128];//입력용 변수 선언
	scanf("%s",filename);//파일명 입력 받기
	Graph_mtx* pGraph_mtx=Ad_mtx(filename);
	if (pGraph_mtx==NULL)
	{
		printf("sth wrong!\n");
		return 0;
	}

	Show(pGraph_mtx);
#ifdef debug
	printf("O\n");
#endif

	printf("Depth First Traversal : ");
	DFS(pGraph_mtx,1,0);//dfs 구성
	printf("%s\n",output_DFS);

	printf("Breadth First Traversal : ");
	BFS(pGraph_mtx);//bfs 구성
	printf("%s\n",output_BFS);

	Destroy_Mtx(pGraph_mtx);
	return 0;
}

static inline void DFS(Graph_mtx* pGraph_mtx,int raw, int col)
{
	if (strchr(output_DFS,*(char*)pGraph_mtx->array[raw][col])==NULL)
	{
		char temp[2]={0};
		temp[0]=*(char*)pGraph_mtx->array[raw][col];
		temp[1]='\0';
		strcat(output_DFS,temp);
		strcat(output_DFS," ");
	}//output에 없으면 추가
	for (int i=1;i<=pGraph_mtx->count;i++)
	{
		if (pGraph_mtx->array[raw][i]!=NULL)
		{
			DFS(pGraph_mtx,i,0);
		}
	}
}

static inline void BFS(Graph_mtx* pGraph_mtx)
{
	/*
	if (strchr(output_BFS,*(char*)pGraph_mtx->array[raw][col])==NULL)
	{
		char temp[2]={0};
		temp[0]=*(char*)pGraph_mtx->array[raw][col];
		temp[1]='\0';
		strcat(output_BFS,temp);
		strcat(output_BFS," ");
	}
	for (int i = 1;i<=pGraph_mtx->count;i++)
	{
		if (pGraph_mtx->array[raw][i]!=NULL)
		{
			if (strchr(output_BFS,*(char*)pGraph_mtx->array[0][i])==NULL)
			{
				char temp[2]={0};
				temp[0]=*(char*)pGraph_mtx->array[0][i];
				temp[1]='\0';
				strcat(output_BFS,temp);
				strcat(output_BFS," ");
			}
		}
	}


	if (raw+1<=pGraph_mtx->count)
	{
		BFS(pGraph_mtx,raw+1,0);
	}
	*/ //무조건 BFS 작동한다는 보장 없음.
	int visited[64]={0};
	int Q[64]={0};
	int front = 0;
	int rear = 0;
	Q[0]=1;//시작점 A는 넣어두자
	rear++;//넣었으니 하나 증가 : 1
	visited[1]=1;//A=1, 1 사용함.
	while (front<rear)
	{
		//Q에서 빼내고
		int that = Q[front++];//
		//BFS 출력에 추가하고
		if (strchr(output_BFS,*(char*)pGraph_mtx->array[that][0])==NULL)
		{
			char temp[2]={0};
			temp[0]=*(char*)pGraph_mtx->array[that][0];
			strcat(output_BFS,temp);
			strcat(output_BFS," ");
		}
		//이어진 열을 Q에 추가
		for (int i = 1;i<=pGraph_mtx->count;i++)
		{
			if ((pGraph_mtx->array[that][i]!=NULL)&&visited[i]!=1)
			{
				Q[rear++]=i;
				visited[i]=1;
			}
		}
	}
}

static inline Graph_mtx* Ad_mtx(const char* filename)
{
	FILE* fp=fopen(filename,"r");
	if (!fp)
	{
		printf("file not exit\n");;
		return NULL;
	}
	char line[256];
	Graph_mtx* pGraph_mtx = CreateMtx();
	while (fgets(line,sizeof(line),fp)!=NULL)
	{
		void* add1=NULL;
		void* add2=NULL;
		char* start=strtok(line," \n");//Q: 현재는 단일 문자만 잘리긴 하는데, 입력이 바뀌면 확신은 없지 않나?
		char* end=strtok(NULL," \n");
		if (end==NULL)//첫 문자만 있다면 --> 시작을 의미. --> 첫 문자를 노드에 추가해야 함.
		{
			char* pch1=(char*)calloc(1,sizeof(char));
			*pch1=*start;// A라는 값을 pch1 주소에 해당하는 칸에 복사
			InsertVtx_mtx(pGraph_mtx,pch1);//노드 추가
		}
		else
		{
			int check1 = 0;//없다고 가정하고, 있으면 1로 바꾸기
			for (int i =1;i<=pGraph_mtx->count;i++)//1~count
			{
				if (*(char*)pGraph_mtx->array[0][i]==*start)
				{
					check1=1;//있으면 1, 없으면 0
					add1=pGraph_mtx->array[i][0];
					break;
				}
			}
			if (!check1)
			{
				char* pch1 = (char*)calloc(1,sizeof(char));
				*pch1 = *start;
				add1=pch1;//엣지용 복사
				InsertVtx_mtx(pGraph_mtx,pch1);
			}//첫 번째 문자가 없다면--> 노드 추가

			int check2 = 0;
			for (int i =1;i<=pGraph_mtx->count;i++)//1~count
			{
				if (*(char*)pGraph_mtx->array[0][i]==*end)
				{
					check2=1;//있으면 1, 없으면 0
					add2=pGraph_mtx->array[0][i];
					break;
				}
			}
			if (!check2)
			{
				char* pch2 = (char*)calloc(1,sizeof(char));
				*pch2 = *end;
				add2=pch2;
				InsertVtx_mtx(pGraph_mtx,pch2);
			}// 두 번째 문자가 없다면 --> 노드 추가

			//엣지 잇기
			AddEdge_mtx(pGraph_mtx,add1,add2);
		}// 일반적인 한 줄이라면-->첫 문자가 있다면 추가, 없으면 패스 ++ 뒷 문자가 있으면 추가 없으면 패스해야 함.
		//그리고 이어야 함.
	}
	fclose(fp);
	return pGraph_mtx;
}

static inline void Show(Graph_mtx* pGraph_mtx)
{
	for (int i = 1;i<=pGraph_mtx->count;i++)
	{
		printf("%c : ",*(char*)pGraph_mtx->array[i][0]);
		for (int t = 1;t<=pGraph_mtx->count ; t++)
		{
			if (pGraph_mtx->array[i][t]!=NULL)
			{
				printf("%c ",*(char*)pGraph_mtx->array[0][t]);
			}
		}
		printf("\n");
	}
}

static inline void Destroy_Mtx(Graph_mtx* pGraph_mtx)
{
	for (int r = 1;r<=pGraph_mtx->count;r++)
	{
		if (pGraph_mtx->array[r][0]!=NULL)
		{
			free(pGraph_mtx->array[r][0]);
		}
	}
	free(pGraph_mtx);
}