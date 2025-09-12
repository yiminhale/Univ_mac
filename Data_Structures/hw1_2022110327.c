#include <stdio.h>
#include <string.h>

int main() 
{ 
    struct { 
        char fullname[50]; //전체 이름을 배열 50칸으로 선언
        char *lastname; //성을 의미하는 포인터
        char *firstname; //이름을 의미하는 포인터
        int age; //나이를 정수로 받음
        char sex; //성별을 문자 하나로 받음.
    } student; 
    // 아래부터 코드 작성. 위는 고정값

/*
전체 로직 설명:
1. "Provide your personal information:" 을 출력
2. "➢ Name : " 을 출력 및 해당 부분에 대한 내용을 입력받아야 함.
3. minseok yi: 영어 이름 -> 띄우고 -> 성 
    ##영어 이름이 아닐 경우 pass
    ##띄워쓰기가 아닐 경우 pass
    ##순서를 바꿀 경우 pass
    - stop 을 입력받을 시 프로그램 종료
4. "➢ Age : " 을 출력 및 해당 부분에 대한 내용을 입력받아야 함.
5. 정수로만 입력받아야 함.
    ## 그 외의 문자 pass
6. 나이를 통해 몇십대인지 구분하는 로직 설계
7. "➢ Sex (M/F) : " 을 출력 및 해당 부분에 대한 내용을 입력받아야 함.
8. M or F 인 단일 문자로만 입력받아야 함.
    ##그 외의 문자를 입력받을 시 다시 입력받도록 설계
9. "Your name is 영어_성 영어_이름, you are in n0s, your sex is M_or_F." 의 양식대로 출력해야 함.
    ##sex는 입력받은대로 그대로 사용하면 문제 없음.
    ##나이 구간은 계산 후 그대로 사용.
    ##이름은 성과 이름의 순서를 바꿔서 출력해야 함.
        ##전체 이름을 받고 이를 배열로 저장했으므로, 이를 처리해야 함.
*/
    char fname[25];
    char lname[25];
    
    while(1) {
        printf("Provide your personal information:\n");// 첫 문장이자 질문 출력. 줄바꿈 실행
        printf("➢ Name : ");//이름에 대한 질문
        scanf("%s", fname);
        
        if(strcmp(fname, "stop") == 0) {
            break;
        }
        // stop은 하나의 단어이므로 firstname으로 처리해도 무방함. 
        scanf("%s", lname);//띄워쓰기로 구분되는 성을 입력받음
        
        strcpy(student.fullname, fname);//전체 이름에 firstname을 복사
        strcat(student.fullname, " ");//이름 성 사이에 띄어쓰기 추가
        strcat(student.fullname, lname);//성 추가해서 완성
        //--- fullname 완성 ---
        student.firstname = fname;//fname을 firstname 포인터에 연결
        student.lastname = lname;//lname을 lastname 포인터에 연결
        
        printf("➢ Age : ");//나이에 대한 질문
        scanf("%d", &student.age);//정수로 나이를 입력받으므로 & 사용 //엔터가 버퍼에 남음.

        int n0s = (student.age / 10)*10;//나눗셈 특성 사용
        
        printf("➢ Sex (M/F) : ");//성에 대한 질문
        scanf(" %c", &student.sex);// 문자 하나로 성별을 입력받으므로 & 사용, **%d 에서 나이를 입력받을 때 \n을 남김. 따라서 \n이 성으로 등록될 위험이 있으므로 공백을 넣어서 실제 문자를 입력받게 함.

        printf("Your name is %s %s, you are in %ds, your sex is %c.\n", 
               student.lastname, student.firstname, n0s, student.sex);
    }
    
    return 0; 
}