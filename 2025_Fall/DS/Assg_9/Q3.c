#include <stdio.h>
#include <stdlib.h>

/*
 * Generic coding 사용 --> 배열이고, 배열 타입을 void* 로 해야겠지.
 * Heap을 구현 --> 왼쪽 자식 = 2i+1, 우측 자식= 2i+2
 * 입력된 파일에서 최소수 구하기 --> 아마 minHeap 구성한 다음 하나 따오면 끝인듯.
 */

typedef struct heap
{
    void **ppArr;
    int size;
    int max;
}heap;
static inline void swap(void** arg1, void**arg2);
static inline void buildminheap(heap *pheap);
static inline void minheapup(heap *pheap,int idx);

int main()
{
    printf("Input file name : ");
    char filename[256]={0};
    scanf("%s",filename);
    //구조체 관련 생성
    heap *pheap=(heap*)calloc(1,sizeof(heap));
    pheap->max=1024;
    pheap->size=0;
    pheap->ppArr=(void**)calloc(1024,sizeof(void*));
    //파일 다루기
    FILE *fp=fopen(filename,"r");//열기
    if (fp==NULL)
    {
        printf("Input file Wrong!\n");
        free(pheap->ppArr);
        free(pheap);
        return 0;
    }//에러 처리
    int *temp=(int*)calloc(1024,sizeof(int));
    while (fscanf(fp,"%d",&temp[pheap->size])==1)
    {
        pheap->ppArr[pheap->size]=temp+pheap->size;
        pheap->size++;
    }
    fclose(fp);//파일닫기
    //minheap 구성하기
    buildminheap(pheap);
    //출력
    printf("Minimum Value is : %d",*(int*)pheap->ppArr[0]);
    //메모리 해제
    free(temp);
    free(pheap->ppArr);
    free(pheap);
    //종료
    return 0;
}

static inline void buildminheap(heap *pheap)//제일 작은 놈이 루트
{
    for (int i=0;i<pheap->size;i++)
    {
        minheapup(pheap,i);
    }
}

static inline void minheapup(heap *pheap,int idx)
{
    //조건 체크
    if (idx<0||pheap->max<idx)
    {
        printf("sth wrong!\n");
        return ;
    }
    //구현
    int parentidx=(idx-1)/2;
    if (*(int*)pheap->ppArr[idx]<*(int*)pheap->ppArr[parentidx])//부모가 자기보다 크다면 스왑해야 함.
    {
        swap(&pheap->ppArr[idx],&pheap->ppArr[parentidx]);
        //재귀해야 하나? ㅇㅇ 맞을듯? 막히면 패스되잖아.
        minheapup(pheap,parentidx);
    }
}

static inline void swap(void** arg1, void**arg2)
{
    void *ptemp=*arg1;
    *arg1=*arg2;
    *arg2=ptemp;
}