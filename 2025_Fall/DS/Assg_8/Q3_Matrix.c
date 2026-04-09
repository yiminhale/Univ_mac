#include "Ad_Matrix3.h"

static inline Graph_mtx* Ad_mtx(const char* filename);
static inline void Show(Graph_mtx* pGraph_mtx);
static inline void MST(Graph_mtx* pGraph_mtx);
static inline void Dij(Graph_mtx* pGraph_mtx);
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
	printf("\n");
	MST(pGraph_mtx);
	printf("\n");
	Dij(pGraph_mtx);
	printf("\n");
	Destroy_Mtx(pGraph_mtx);
	return 0;
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
		char* weight=strtok(NULL," \n");
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
			//가중치 가공
			int w=atoi(weight);
			//엣지 잇기
			AddEdge_mtx(pGraph_mtx,add1,add2,w);
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
			if (*(int*)pGraph_mtx->array[i][t]!=1000)
			{
				printf("%c (%d) ",*(char*)pGraph_mtx->array[0][t],*(int*)pGraph_mtx->array[i][t]);
			}
		}
		printf("\n");
	}
}
static inline void MST(Graph_mtx* pGraph_mtx)
{
	printf("Minimum Spanning Tree : \n");
	int count=0;
	while (pGraph_mtx->array[0][count+1]!=NULL)
	{
		++count;//node 총 몇개인지 세기
	}
	int vstd[256]={0};//vstd['A']=1 or 0으로 사용
	char* T[2][256]={0};//어디서 어디로 가는지 엣지 의미.
	char* TV[256]={0};
	int wgt[256]={0};//가중치 배열
	TV[0]=(char*)pGraph_mtx->array[1][0];
	vstd[*(char*)pGraph_mtx->array[1][0]]++;
	void* (*parr)[64]=pGraph_mtx->array;//사용하기 편하게 지정
	for (int i = 0;i<count-1;i++)//01234 : 5개
	{
		int min_w=9999;//최종 후보의 가중치
		int raw=1;//행 지정. 시작은 1행부터니까.
		for (int t=0;t<i+1;t++)//현재 트리에 있는 노드 수 - 1 만큼 위치 옮겨야지
		{
			for (int v=1;v<=count;v++)//123456//배열의 열이 6개니까
			{
				if (vstd[*(char*)parr[0][v]]!=0)
				{
					continue;
				}//방문했다면
				else if (*(int*)parr[raw][v]==1000)
				{
					continue;
				}//떨어져 있다면
				else
				{
					if (*(int*)parr[raw][v]<min_w)
					{
						min_w=*(int*)parr[raw][v];
						wgt[i]=*(int*)parr[raw][v];
						T[0][i]=(char*)parr[raw][0];
						T[1][i]=(char*)parr[0][v];
						TV[i+1]=(char*)parr[0][v];
					}
				}//방문하지도 않았고 연결되어 있다면 --> 가장 작은 가중치를 가지고 있는지 체크 후 삽입해야 함.
			}
			for (int r = 1;r<=count;r++)
			{
				if (*(char*)parr[0][r]==*TV[t+1])
				{
					raw = r;
					break;
				}
			}//다음 행 raw 찾기
		}
		vstd[*TV[i+1]]++;//방문 표시
	}

	for (int i = 0;i<count-1;i++)
	{
		printf("%c %c (%d)\n",*T[0][i],*T[1][i],wgt[i]);
	}//출력
}
static inline void Dij(Graph_mtx* pGraph_mtx)
{
	printf("Shortest Path from %c : \n",*(char*)pGraph_mtx->array[1][0]);
	int count=0;//갯수 세기
	while (pGraph_mtx->array[0][count+1]!=NULL)
	{
		++count;//node 총 몇개인지 세기
	}

	int d[256]={0};
	for (int i = 0;i<256;i++)
	{
		d[i]=1000;//초기화
	}
	d[*(char*)pGraph_mtx->array[1][0]]=0;
	int vstd[256]={0};
	void* (*parr)[64]=pGraph_mtx->array;//사용하기 편하게 지정
	for (int i=1;i<count;i++)//12345 6번
	{
		//구성--Prim 과 거의 유사
		//다음 행으로 이동 - 미방문 노드 중 d값 최소인 행 찾기
		int raw = -1;
		int mdist = 1001;
		for (int r=1;r<=count;r++)
		{
			if (vstd[*(char*)parr[r][0]]==0/*방문 안했다면*/ && d[*(char*)parr[r][0]]<mdist/*거리를 아는 노드라면*/)
			{
				mdist = d[*(char*)parr[r][0]];
				raw = r;
			}
		}

		//이동 시 dist 수정해서 가져가야 함.
		int dist = d[*(char*)parr[raw][0]];//누적 거리. 다음 노드에서 뻗어나갈 때 누적 거리 계산해야 함.

		for (int v = 1;v<=count;v++)
		{
			//1. 1000일 경우 : 패스
			if (*(int*)parr[raw][v] == 1000 )
			{
				continue;
			}
			//2. 1000보다 짧을 경우-->현재 d 보다 짧은지 점검 -->짧다면 대체, 길다면 패스
			int new_dist = dist + *(int*)parr[raw][v];
			if (new_dist < d[*(char*)parr[0][v]])
			{
				d[*(char*)parr[0][v]] = new_dist;
			}//현재 d 보다 짧다면
		}//각 행 내부

		//방문 표시 남기기
		vstd[*(char*)parr[raw][0]]++;//1st: A //2nd:

		//출력
		for (int t=2;t<=count;t++)
		{
			printf("%c %c : %d\n", *(char*)pGraph_mtx->array[1][0], *(char*)pGraph_mtx->array[t][0],
				   d[*(char*)pGraph_mtx->array[t][0]]);
		}
		printf("\n");
	}
	//최종 출력
	for (int i=2;i<=count;i++)
	{
		printf("%c %c : %d\n",*(char*)pGraph_mtx->array[1][0],*(char*)pGraph_mtx->array[i][0],d[*(char*)pGraph_mtx->array[i][0]]);
	}
}

static inline void Destroy_Mtx(Graph_mtx* pGraph_mtx)
{
	for (int r=1;r<=pGraph_mtx->count-1;r++)
	{
		for (int col=r+1;col<=pGraph_mtx->count;col++)
		{
			if (pGraph_mtx->array[r][col]!=NULL&&*(int*)pGraph_mtx->array[r][col]!=1000)
			{
				free(pGraph_mtx->array[r][col]);
			}
		}
	}
	for (int i = 0;i<=pGraph_mtx->count;i++)
	{
		if (pGraph_mtx->array[i][0]!=NULL)
		{
			free(pGraph_mtx->array[i][0]);
		}
	}
	free(pGraph_mtx->array[1][1]);
	free(pGraph_mtx);
}