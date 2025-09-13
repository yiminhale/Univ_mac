/*Req
- struct, dynamic memory alloc 사용
- 나이는 Z+, 성적은 [0,100] 범위 이내여야 함.
- sorting: 오름차순. **동일 순위 내의 정렬은 순서 상관 없음 -> 동일 순위에서는 input.txt의 순서에 따르도록 만들것임.
	-성: alphabet 순
	-나이 & 성적: 정수 비교후 오름차순
 */
/////////////////////전처리기 호출
#include <stdio.h>
/////////////////////함수 선언
void print_horizontal_rule ();
void print_menu();
int print_empty_file_sort();
int print_quit();
int print_error_yo();
void input_and_check_file_condition ();
////////////////////전역변수 선언
int menu_btn = 0;//menu 선택값을 위한 변수 선언 및 초기화
////////////////////main 실행 부분
int main(){
	print_horizontal_rule();//시작 알림
	print_menu();//첫 메뉴 시작 부분 프린트
	/////////////////////////////////////////////시작 부분 갈림길 로직 start
	scanf("%d", &menu_btn);//menu 입력 받아서 저장
	if (menu_btn == 2)
	{
		print_empty_file_sort();
	}
	else if (menu_btn == 3)
	{
		print_quit();
	}
	else if (menu_btn == 1)//menu 파일 입력
	{
		input_and_check_file_condition();

	}
	/////////////////////////////////////////////시작 부분 갈림길 로직 end: 함수로 만들지 main에 남길지 결정해야 함.
}
/////////////////////////////////////////////////
void print_horizontal_rule ()// 구분선 출력
{
	printf("============================\n");
}
//////////////////////////////////////////////////
void print_menu()//메뉴 보여주기
{
	printf("1) Insert\n2) Sort\n3) Quit\nSelect a menu : ");
}
//////////////////////////////////////////////////
int print_empty_file_sort()//현재 프로그램에 sort할 파일이 없을 경우에만 사용되어야 함. 중요한 것은 빈 파일에 대한 검사 로직은 따로 구현해야 함.
{
	printf("\nResult : There is no data to be sorted. Program terminates.\n");//sort할 데이터 없음 알림
	print_horizontal_rule();
	return 0;
}
//////////////////////////////////////////////////
int print_quit()//menu에서 3번이 입력될 경우 사용. 즉, '3번이 입력될 경우'에 대한 로직은 따로 구현
{
	print_horizontal_rule();
	return 0;
}
//////////////////////////////////////////////////
int print_error_yo()//나이오류가 결정났을 때 사용. 즉, 검사 로직은 따로 구현
{
	printf("Result : The age cannot be a negative number. Program terminates.\n");
	print_horizontal_rule();
	return 0;
}
/////////////////////////////////////////////////
void input_and_check_file_condition()//1번을 통해 파일 받는 로직 구현
{
	printf("\nFile name : ");
	scanf("");
}