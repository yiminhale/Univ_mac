#ifndef ASSG_6_LIST_ARRAY_H
#define ASSG_6_LIST_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Element;

typedef struct List
{
	int size;
	Element *array;//사이즈를 받아야 함
	int pLoc;
	int count;
}List;

static inline List *CreateList(int size)
{
	List *pList=(List*)calloc(1,sizeof(List));
	if (pList==NULL)
	{
		return NULL;
	}
	pList->size=size;
	pList->array=(Element*)calloc(size,sizeof(Element));
	pList->pLoc=0;
	pList->count=0;
	return pList;
}

static inline void insert(List *pList,Element data)
{
	if (pList->count==pList->size)//안이 꽉 찬 경우
	{
		printf("array is Full!\n");
		return ;
	}

	if (pList->count==0)
	{
		pList->array[0]=data;
		pList->count++;
	}
	else//처음이 아닐 경우
	{
		//첫 위치에 넣을 경우
		if (data<pList->array[0])
		{
			for (int i = pList->count;i;i--)
			{
				pList->array[i]=pList->array[i-1];
			}
			pList->array[0]=data;
			pList->count++;
		}
		//제일 마지막에 넣을 경우
		else if (pList->array[pList->count-1]<data)
		{
			pList->array[pList->count]=data;
			pList->count++;
		}
		//중간에 넣을 경우
		else
		{
			while (pList->array[pList->pLoc]<data)//pLoc을 data보다 큰 배열을 만날 때까지 증가시킴
			{
				pList->pLoc++;
			}
			for (int i = pList->count;pList->pLoc<i;i--)
			{
				pList->array[i]=pList->array[i-1];
			}
			pList->array[pList->pLoc]=data;
			pList->pLoc=0;//썼으니 0으로
			pList->count++;
		}
	}
}

static inline Element search(List *pList, Element data)
{
	for (int i = 0;i<pList->count;i++)
	{
		if (pList->array[i]==data)
		{
			return data;
		}
	}
	return -1;
}

static inline Element delete(List *pList, Element data)
{
	Element tree = search(pList,data);
	if (tree==data)//찾는게 있다면
	{
		pList->pLoc=0;//초기화
		while (pList->array[pList->pLoc]!=data)
		{
			pList->pLoc++;
		}
		Element rtn_value=pList->array[pList->pLoc];
		for (int i = pList->pLoc;i<pList->count-1;i++)
		{
			pList->array[i]=pList->array[i+1];
		}
		pList->count--;
		printf("%d was removed.\n",data);
		return rtn_value;
	}
	else if (tree==-1)//찾는게 없다면
	{
		printf("My List doesn't have %d.\n",data);
		return 0;
	}
}

static inline void traverse(List *pList)
{
	for (int i = 0;i<pList->count;i++)
	{
		printf(" %d",pList->array[i]);
		if (i!=pList->count-1)
		{
			printf(",");
		}
	}
}

static inline void menu()
{
	printf("In (0), Search (1), Out (2), Exit (3) : ");
}

static inline int cycle(List *pList)
{
	menu();
	int input_menu=-1;
	scanf("%d",&input_menu);
	if (input_menu==0)//in
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
	else if (input_menu==1)//search
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
	else if (input_menu==2)//out
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
	else if (input_menu==3)//exit
	{
		free(pList->array);
		free(pList);
		return 0;
	}
}

#endif //ASSG_6_LIST_ARRAY_H