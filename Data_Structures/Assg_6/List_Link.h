#ifndef ASSG_6_LIST_LINK_H
#define ASSG_6_LIST_LINK_H

#include <stdio.h>
#include <stdlib.h>

typedef int Element;//int를 대상으로 하니까.

typedef struct Node
{
	Element data;//데이터
	struct Node *next;//따라가면 ListNode가 나옴.
}Node;

typedef struct List
{
	int count;//몇개 들어 있는지 세는
	Node *head;//첫 번째 원소 가리키는
	Node *pPre;//
	Node *pLoc;
}List;

static inline List *CreateList()
{
	List *pList= (List*)calloc(1,sizeof(List));
	if (pList==NULL)
	{
		return NULL;
	}
	pList->head = NULL;
	pList->count=0;
	pList->pPre=NULL;
	pList->pLoc=NULL;
	return pList;
}

static inline void insert(List *pList, Element data)
{
	Node *pNewNode = (Node*)calloc(1,sizeof(Node));
	if (pNewNode==NULL)
	{
		return ;
	}
	//노드 값 채우기
	pNewNode -> data = data;
	//원하는 부분에 넣기
	if (pList->count ==0)//현재 비어 있다면
	{
		pNewNode->next=NULL;//새로 추가하는 노드의 next 널
		pList->head=pNewNode;//헤드가 노드를 가리키도록
		pList->count++;//카운트 하나 늘리기
	}
	else//비어 있지 않다면: 하나 이상 있다면
	{
		if (pList->count==1)//하나 들어 있다면
		{
			pList->pLoc=pList->head;//pLoc을 하나뿐인 노드의 주소로
			if (pNewNode->data<pList->pLoc->data)//새 데이터가 하나의 데이터보다 작다면
			{
				pNewNode->next=pList->pLoc;
				pList->head=pNewNode;
				pList->count++;
			}
			else if (pList->pLoc->data < pNewNode->data)
			{
				pList->pLoc->next=pNewNode;
				pList->count++;
				pNewNode->next=NULL;
			}
		}
		else//둘 이상 들어 있다면
		{
			pList->pLoc=pList->head->next;//pLoc을 두번째 원소의 주소로
			pList->pPre=pList->head;//pPre를 첫 번째 원소의 주소로
			while (1)//반복해라
			{
				if (pList->pPre->data< pNewNode->data && pNewNode->data <pList->pLoc->data)//사이에 있다면
				{
					pNewNode->next=pList->pLoc;
					pList->count++;
					pList->pPre->next=pNewNode;
					break;
				}
				else if (pNewNode->data<pList->head->data)//첫부분보다 앞에 있을 때
				{
					pNewNode->next=pList->head;
					pList->head=pNewNode;
					pList->count++;
					break;
				}
				else if (pList->pLoc->data < pNewNode->data && pList->pLoc->next==NULL )//우측 끝보다 클때
				{
					pNewNode->next=NULL;
					pList->pLoc->next=pNewNode;
					pList->count++;
					break;
				}
				else if (pList->pLoc->data<pNewNode->data && pList->pLoc->next!=NULL)//더 탐색해야 할 때
				{
					pList->pLoc=pList->pLoc->next;
					pList->pPre=pList->pPre->next;
				}
			}
		}
	}
}

static inline Element search(List *pList, Element data)//반환값: 찾았다면 찾은 대상, 못찾았다면 -1 반환.
{
	Node *pcur=pList->head;//헤드가 가리키는 대상 지정
	for (int i = pList->count;i;i--)//들어있는 갯수만큼 반복한다.
	{
		if (pcur->data==data)
		{
			return data;//for 종료
		}
		else
		{
			pcur=pcur->next;//한칸 우측으로.
		}
	}
	return -1;//못찾았을 경우 -1 반환
}

static inline Element delete(List *pList,Element data)
{
	Element tree = search(pList,data);//분기점
	if (tree==data)//삭제하려는 데이터가 있다면
	{
		pList->pLoc=pList->head;//조정
		pList->pPre=NULL;//초기 조정
		while (pList->pLoc->data!=data)
		{
			pList->pPre=pList->pLoc;
			pList->pLoc=pList->pLoc->next;
		}
		//찾았다면
		if (pList->pPre==NULL)//첫 원소를 찾았을 경우
		{
			pList->head=pList->pLoc->next;
		}
		else
		{
			pList->pPre->next=pList->pLoc->next;//마지막이라면 pPre의 next는 NULL됨
		}
		Element temp=pList->pLoc->data;
		free(pList->pLoc);
		pList->count--;
		printf("%d was removed.\n",data);
		return temp;
	}
	else if (tree==-1)
	{
		printf("My List doesn't have %d.\n",data);
		return 0;
	}
}

static inline void traverse(List *pList)
{
	if (pList->count==0)
	{
		return ;
	}
	Node *pnow = pList->head;
	while (pnow!=NULL)
	{
		printf(" %d",pnow->data);
		if (pnow->next!=NULL)//다음이 있다면
		{
			printf(",");
		}
		pnow=pnow->next;//마지막일 경우 널이 됨
	}
}

static inline void menu()
{
	printf("In (0), Search (1), Out (2), Exit (3) : ");
}

static inline int cycle(List *pList)
{
	menu();//메뉴 출력
	int input_menu=-1;
	scanf("%d",&input_menu);

	if (input_menu==0)
	{
		printf("In : ");
		Element input_in=-1;
		scanf("%d",&input_in);
		insert(pList,input_in);
		printf("The current status of List :");
		traverse(pList);
		putchar('\n');
		putchar('\n');
		cycle(pList);//재귀
	}
	else if (input_menu==1)//검색
	{
		printf("Search : ");
		Element input_in=-1;
		scanf("%d",&input_in);
		Element output =search(pList, input_in);
		if (output==input_in)
		{
			printf("My List has %d.\n", input_in);
		}
		else
		{
			printf("My List doesn't have %d.\n",input_in);
		}
		printf("The current status of List :");
		traverse(pList);
		putchar('\n');
		putchar('\n');
		cycle(pList);//재귀
	}
	else if (input_menu==2)//삭제
	{
		printf("Out : ");
		int input_in=-1;
		scanf("%d",&input_in);
		delete(pList, input_in);

		printf("The current status of List :");
		traverse(pList);
		putchar('\n');
		putchar('\n');
		cycle(pList);//재귀
	}
	else if (input_menu==3)
	{
		if (pList->head==NULL)
		{
			free(pList);
			return 0;
		}
		Node *pdel = pList->head;
		Node *pdel2 = pdel->next;
		do{
			free(pdel);
			pdel=pdel2;
			if (pdel2!=NULL)
			{
				pdel2=pdel2->next;
			}
		}while (pdel!=NULL);
		free(pList);
		return 0;
	}
}


#endif //ASSG_6_LIST_LINK_H
