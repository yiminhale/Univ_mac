#ifndef BEFORE_MID_EX_FUNC_H
#define BEFORE_MID_EX_FUNC_H
#include "Customer_Array.h"
#include "Table_Link.h"

static inline void stat(FAR *pFAR,Queue *current);

static inline int cycle(FAR *pFAR,Queue *current)//하나의 사이클 함수
{

	printf("Order (0), Serve (1), Exit (2) : ");//단순 출력
	int i_menu=-1;//메뉴 입력값 저장 변수 선언
	scanf("%d",&i_menu);//메뉴 입력값 저장
	//ㄷ 과정
	if (i_menu==0)//order
	{
		printf("Order : ");//단순 출력
		Data i_queue;
		scanf("%s",i_queue);//i_queue자체가 주소이므로 그 주소에 문자열로 저장
		Enqueue(pFAR,i_queue);//큐에 추가

		stat(pFAR,current);//상태 보여주기
		putchar('\n');//줄 띄우기
		cycle(pFAR, current);//반복
	}
	else if (i_menu==1)//serve
	{
		printf("Serve : ");//단순 출력
		/* 스택을 사용하지 않고 처리
		Data *serving = Dequeue(pFAR);//*serving에 '2' '3' '1' '\0' 으로 저장. serving은 주소임.
		for (size_t i = strlen((char *)serving);i;i--)//casting 필요. 오류 발생시 수정
		{
			int output = ((char *)serving)[i-1]-'0';//문자열을 정수로 바꾸기
			switch (output)
			{
			case 1: printf("Ice cream");break;
			case 2: printf("Bibimbab");break;
			case 3: printf("Bulgogi");break;
			case 4: printf("Coffee");break;
			case 5: printf("Noodle");break;
			default : break;
			}
			if (i!=1)//마지막이 아니라면
			{
				printf(", ");//이어지는 문장
			}
		}
		*/
		//////스택을 사용하여 처리
		Head *pStack = CreateStack(1024);//스택 생성
		Data *serving = Dequeue(pFAR);
		for (int i = 0;i<strlen((char *)serving);i++)//입력
		{
			Push(pStack,((char *)serving)[i]-'0');//2 3 1 저장됨.
		}

		for (int i =0;i<strlen((char *)serving);i++)//빼내서 출력
		{
			int output = Pop(pStack);
			switch (output)
			{
			case 1: printf("Ice cream");break;
			case 2: printf("Bibimbab");break;
			case 3: printf("Bulgogi");break;
			case 4: printf("Coffee");break;
			case 5: printf("Noodle");break;
			default: break;
			}
			if (i!=strlen((char *)serving)-1)//마지막이 아니라면
			{
				printf(", ");//이어지는 문장
			}
		}
		DestroyStack(pStack);//사용 후 폐기
		///////
		//상태
		putchar('\n');//줄 띄우기
		stat(pFAR,current);//상태출력
		//반복
		putchar('\n');//줄 띄우기
		cycle(pFAR, current);//반복
	}
	else if (i_menu == 2)//exit
	{
		//queue 메모리 파괴
		while (pFAR->prear!=NULL)
		{
			Dequeue(pFAR);
		}
		free(pFAR);//FAR도 파괴하고 종료.
		return 0;// 종료
	}
	else
	{
		printf("Wrong!\n");
		return 0;//종료
	}
}

static inline void stat(FAR *pFAR,Queue *current)//현재 테이블 상태 출력
{
	current = pFAR->pfront;
	printf("Stat : ");
	while (current!=NULL)//프론트가 널이 아니라면 널이 될때까지 실행
	{
		printf("%s ",current->content);
		current=current->next;//다음 부분 지정. 마지막이라면 여기서 NULL이 됨.
	}
	printf("(%d)",pFAR->count);
}


#endif //BEFORE_MID_EX_FUNC_H