#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * 코딩 연습
 * 1. 펑션 포인터---
 * 2. BST 삭제 로직 구현---
 * 3. 다익스트라
 * 4. 프림
 * 5. 힙소트
 * 6. 리힙업, 리힙다운---
 */

//다익스트라 프림 위한 선언
typedef struct adj_mtx
{
    int mtx[256][256];
    int visited[256];
    int parent[256];
    int distance[256];
    int size;
}adj_mtx;
//자주 사용하는 일반 함수들 선언
void swap(void** para1, void** para2)
{
    void *temp= *para1;
    *para1 = *para2;
    *para2 = temp;
}
int chartoint(char a)
{
    return ((int)a-'A');
}
char inttochar(int i)
{
    return ((char) i+'A');
}
//func pointer: 문자열 길이 비교로 해보자.
int lencmp(void *data1, void *data2)
{
    int rtn, len1,len2;
    len1=(int)strlen((char*)data1);
    len2=(int)strlen((char*)data2);
    rtn = (len1>len2) ? 1: -1;
    if (len1==len2) rtn=0;
    return rtn;
}
typedef struct fpoi
{
    int (*compare)(void*arg1,void*arg2);
}fpoi;
fpoi* create_fpoi(int (*func)(void* arg1, void*arg2))
{
    fpoi* pfpoi = (fpoi*)calloc(1,sizeof(fpoi));
    pfpoi->compare=func;
    return pfpoi;
}
//추후 사용에서 create_fpoi(lencmp) 로 함수 사용.

//BST 삭제 로직
//BST 위한 선언
typedef struct bst_node
{
    void* data;
    struct bst_node* left;
    struct bst_node* right;
    int (*compare)(void* arg1, void* arg2);
}bst_node;
int compare_int(void* data1, void* data2)
{
    if (*(int*)data1>*(int*)data2){ return 1; }
    else if (*(int*)data1<*(int*)data2){ return -1; }
    else{return 0;}
}
/*
 * 말로 설명.
 * 1. 삭제할 부분까지 도달.
 * 2. 핵심은 삭제할 부분의 좌측 서브트리에서 제일 큰놈을 올리던가, 우측 서브트리에서 제일 작은놈을 올려야 함.
 * 즉, 더블포인터 사용할지 고민하고,
 * 자식이 없다면 그냥 삭제, 좌측자식밖에 없다면 그냥 좌측 자식을 올리면 되고, 우측 자식밖에 없다면 우측 자식만 올리면 됨. 자식이 2개라면 서브트리 최대 최소 확인할 것.
 */
bst_node* create_bst(int(*func)(void* arg1,void* arg2),void* data)
{
    bst_node* pbst=(bst_node*)calloc(1,sizeof(bst_node));
    pbst->data=data;
    pbst->compare=func;
    return pbst;
}
bst_node* delete_bst(bst_node* pbst,void* data,int (*cmp)(void* arg1,void* arg2))
{
    if (pbst==NULL) return NULL;
    //삭제 부분까지 도달. 업으면 return 0;
    if (cmp(pbst->data,data)<0)//우측으로 가야 한다면
    {
        pbst->right=delete_bst(pbst->right,data,cmp);
    }
    else if (cmp(pbst->data,data)>0)//좌측으로 가야 한다면
    {
        pbst->left=delete_bst(pbst->left,data,cmp);
    }
    else//찾음.
    {
        //솔로라면
        //좌측 자식밖에 없다면
        if (pbst->right==NULL)
        {
            bst_node* temp=pbst;
            pbst=pbst->left;
            free(temp);
            return pbst;
        }
        //우측 자식 밖에 없다면
        if (pbst->left==NULL)
        {
            bst_node* temp=pbst;
            pbst=pbst->right;
            free(temp);
            return pbst;
        }
        //자식이 2개라면--> 좌측에서 제일 큰놈 델고오자!
        bst_node* max=pbst->left;
        while (max->right!=NULL)
        {
            max=max->right;
        }
        pbst->data=max->data;//값만 복사.
        pbst->left=delete_bst(pbst->left,max->data,cmp);
    }
    return pbst;
}
//다익스트라

//프림

//힙 위한 구조체
int compare_str(void* data1, void* data2);
typedef struct heap
{
    void **h;
    int len;
    int max_size;
    int (*compare)(void* arg1,void*arg2);
}heap;
heap* create_heap(int size,int (*func)(void *arg1,void* arg2))
{
    heap* pheap=(heap*)calloc(1,sizeof(heap));
    pheap->max_size=size;
    pheap->len=0;
    pheap->h=(void**)calloc(1024,sizeof(void*));
    pheap->compare= func;
    return pheap;
}
//문자열 우선순위라고 가정해보자.
int compare_str(void* data1, void* data2)
{
    char *str1 = (char*)data1;
    char *str2 = (char*)data2;
    int result = strcmp(str1,str2);
    return result;
}
//리힙업==추가시에 사용
void maxheapup(heap* pheap,int i)
{
    if (pheap==NULL) return ;
    if (i==0) return ;
    int parent=(i-1)/2;
    int result = pheap->compare(pheap->h[i],pheap->h[parent]);//자식이 우선이라면 -1, 부모가 우선이라면 1, 같으면 0
    if (result<0)//부모보다 자신이 우선할 경우 스왑 후 재귀
    {
        swap(&pheap->h[i],&pheap->h[parent]);
        maxheapup(pheap,parent);
    }
}
//리힙다운==삭제시에 사용
void maxheapdown(heap* pheap, int idx)
{
    if (pheap==NULL) return ;
    int left=2*idx+1;
    int right=2*idx+2;
    int target=idx;
    if (left>=pheap->len)//자식이 없다면 종료.
    {
        return ;
    }
    if (right<pheap->len)//우측 자신 존재하는지 확인.
    {
        int child_cmp=pheap->compare(pheap->h[left],pheap->h[right]);
        target=(child_cmp<0)?left:right;
    }
    int height_cmp=pheap->compare(pheap->h[idx],pheap->h[target]);//음수면 자신이 우선, 양수면 자식중 큰놈이 우선.
    if (height_cmp>0)//자식이 우선이라면
    {
        swap(&pheap->h[idx],&pheap->h[target]);
        maxheapdown(pheap,target);
    }
}
//힙소트
void heap_sort(heap* pheap)
{
    //build heap 먼저 해야 함.: 삽입 후 maxheapup 반복.
    int ori = pheap->len;
    for (int i = 0;i<ori-1;i++)//들어있는 수 - 1만큼 반복
    {
        swap(&pheap->h[0],&pheap->h[pheap->len-1]);//제일 큰놈 끌어내고
        pheap->len--;//벽 하나 감소시키기.
        maxheapdown(pheap,0);//힙 재구성
    }
    pheap->len=ori;
}
int main()
{

    return 0;
}