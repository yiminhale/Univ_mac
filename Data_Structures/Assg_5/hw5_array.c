#include "Queue_Array.h"
////////////////////함수 디자인
void menu();
int condition_menu(int input_menu,Circular_Queue *pC_Queue);
void current_queue(Circular_Queue *pC_Queue);
////////////////////메인 실행 부분
int main() {
    menu();//메뉴판 출력
    int input_menu=-1;//메뉴 입력에 대한 변수 선언 및 초기화
    scanf("%d",&input_menu);//메뉴 입력값 저장
    Circular_Queue *pC_Queue = CreateQueue(64);//일단 FAR 생성
    if (pC_Queue==NULL)//생성 확인
    {
        return 0;
    }
    condition_menu(input_menu,pC_Queue);
    return 0;
}

void menu()
{
    printf("In (0), out (1), exit (2) : ");
}

int condition_menu(int input_menu,Circular_Queue *pC_Queue)
{
    Data customer_name;//고객명 변수 선언
    if (input_menu==0)//추가해야 함.
    {
        printf("Customer : ");//일반 출력
        scanf(" %[^\n]",customer_name);//입력 받아서 변수에 저장. 띄워쓰기 반영해야하므로, 줄바꿈 전까지 읽게 조정.
        Enqueue(pC_Queue,customer_name);//큐에 추가
        current_queue(pC_Queue);//현재 큐 상태 출력
        //반복
        putchar('\n');//한줄 띄우기
        menu();//메뉴 출력
        scanf("%d",&input_menu);//메뉴 입력값 저장
        condition_menu(input_menu,pC_Queue);//재귀호출
    }
    else if (input_menu==1)//dequeue해야 함.
    {
        if (pC_Queue->count==0)//queue가 비어있을 경우
        {
            printf("Queue is Empty!\n");
            return 0;
        }
        Data *temp = Dequeue(pC_Queue);
        strcpy(customer_name,*temp);
        free(temp);
        printf("Customer dequeued : %s\n",customer_name);
        current_queue(pC_Queue);
        //반복
        putchar('\n');//한줄 띄우기
        menu();//메뉴 출력
        scanf("%d",&input_menu);//메뉴 입력값 저장
        condition_menu(input_menu,pC_Queue);//재귀호출
    }
    else if (input_menu==2)
    {
        free(pC_Queue->queue);
        free(pC_Queue);
        return 0;//종료해야 함.
    }
    else
    {
        return 0;
    }
}

void current_queue(Circular_Queue *pC_Queue)
{
    /*
    printf("The current status of Queue : (");//단순출력
    Circular_Queue *current = pC_Queue->front;
    int index=1;
    for (int i = pC_Queue->count;i;i--)//next가 자기를 가리키고, rear를 가리키는 지점이 같을 경우
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
    if (pC_Queue->count==0)
    {
        printf(")\n");
    }
    */
    printf("The current status of Queue : (");//단순출력
    int index = 1;
    int current = pC_Queue->front;
    for (int i = pC_Queue->count;i;i--)
    {
        printf("%s%d",pC_Queue->queue[(current+1)%pC_Queue->size],index);
        if (pC_Queue->queue[(current+2)%pC_Queue->size][0]!='\0')//다음이 비어있는지 확인. 포인터, 배열 특성 활용
        {//다음칸이 비어있지 않으면
            printf(", ");
            current = (current+1)%pC_Queue->size;//한칸 업
            index++;
        }
        else//다음 칸이 비어있다면 현재 위치에서 마감해야 함.
        {
            printf(")\n");
        }
    }
    if (/*pC_Queue->rear==current*/pC_Queue->count==0)//아무것도 없을 경우 괄호는 닫아야지
    {
        printf(")\n");
    }
}