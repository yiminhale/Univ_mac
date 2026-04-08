#include "Queue_Link.h"
////////////////////함수 디자인
void menu();
int condition_menu(int input_menu,FAR *pFAR);
void current_queue(FAR *pFAR);
////////////////////메인 실행 부분
int main() {
    menu();//메뉴판 출력
    int input_menu=-1;//메뉴 입력에 대한 변수 선언 및 초기화
    scanf("%d",&input_menu);//메뉴 입력값 저장
    FAR *pFAR = CreateQueue();//일단 FAR 생성
    if (pFAR==NULL)//생성 확인
    {
        return 0;
    }
    condition_menu(input_menu,pFAR);
    return 0;
}

void menu()
{
    printf("In (0), out (1), exit (2) : ");
}

int condition_menu(int input_menu,FAR *pFAR)
{
    char customer_name[1024];//고객명 변수 선언
    if (input_menu==0)//추가해야 함.
    {
        printf("Customer : ");//일반 출력
        scanf(" %[^\n]",customer_name);//입력 받아서 변수에 저장. 띄워쓰기 반영해야하므로, 줄바꿈 전까지 읽게 조정.
        Enqueue(pFAR,customer_name);//큐에 추가
        current_queue(pFAR);//현재 큐 상태 출력
        putchar('\n');//한줄 띄우기
        menu();//메뉴 출력
        scanf("%d",&input_menu);//메뉴 입력값 저장
        condition_menu(input_menu,pFAR);//재귀호출
    }
    else if (input_menu==1)//dequeue해야 함.
    {
        if (pFAR->count==0)//queue가 비어있을 경우
        {
            printf("Queue is Empty!\n");
            return 0;
        }
        Data *temp = Dequeue(pFAR);
        strcpy(customer_name,*temp);
        free(temp);
        printf("Customer dequeued : %s\n",customer_name);
        current_queue(pFAR);
        putchar('\n');//한줄 띄우기
        menu();//메뉴 출력
        scanf("%d",&input_menu);//메뉴 입력값 저장
        condition_menu(input_menu,pFAR);//재귀호출
    }
    else if (input_menu==2)
    {
        while (pFAR->pfront!=NULL)//node 전부 해제
        {
            Queue *temp = pFAR->pfront;
            pFAR->pfront = pFAR->pfront->next;//프론트 조정
            free(temp);//해제
        }
        free(pFAR);
        return 0;//종료해야 함.
    }
    else
    {
        return 0;
    }
}

void current_queue(FAR *pFAR)
{
    printf("The current status of Queue : (");//단순출력
    Queue *current = pFAR->pfront;
    int index=1;
    for (int i = pFAR->count;i;i--)//next가 자기를 가리키고, rear를 가리키는 지점이 같을 경우
    {
        printf("%s%d",current->content,index);//출력
        if (current->next!=NULL)//current 다음이 존재할 경우
        {
            printf(", ");//콤마와 띄워쓰기
            current=current->next;//한칸 이동.
            index++;//숫자 올리기
        }
        else
        {
            printf(")\n");
        }
    }
    if (pFAR->count==0)
    {
        printf(")\n");
    }
}