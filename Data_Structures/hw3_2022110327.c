/*Req
- struct, dynamic memory alloc 사용 --완료
- 나이는 Z+, 성적은 [0,100] 범위 이내여야 함.--완료
- sorting: 오름차순. **동일 순위 내의 정렬은 순서 상관 없음 -> 동일 순위에서는 input.txt의 순서에 따르도록 만들것임.
	-성: alphabet 순
	-나이 & 성적: 정수 비교후 오름차순
 */
/////////////////////////////////////////////////전처리기 호출
#include <stdio.h>
#include <stdlib.h>
/////////////////////////////////////////////////함수 선언
void print_horizontal_rule ();//1번 과정
void print_menu();
int print_empty_file_sort();
int print_quit();
int print_error_yo();
int print_error_sr();
void print_sort_menu();
int logic_of_2();//메뉴 출력
int logic_of_3();//파일 입력 받고 제어하기
int count_student(FILE *fp);//파일에 존재하는 학생 수 세기
int logic_of_4();//파일 조건 검사
void logic_of_5();//Result 출력으로 파일 내용 보여주기
/////////////////////////////////////////////////전역변수 선언
int menu_btn = 0;//menu 선택값을 위한 변수 선언 및 초기화
int num_of_student=0;
struct student *students=NULL;
FILE *fp=NULL;
/////////////////////////////////////////////////학생 정보를 저장할 구조체 선언
struct student
{
	char name[50];
	int age;
	int math;
	int english;
	int history;
};
/////////////////////////////////////////////////main 실행 부분
int main(){
	print_horizontal_rule();//1번 과정.
	int result_of_2=logic_of_2();//2번 과정. 1을 입력받을 때 1을 반환하고, 이것이 3번 과정의 트리거가 되어야 함.
	if (result_of_2 == 1)
	{
		logic_of_3();//3번 과정. Input 받기.
	}

}
/////////////////////////////////////////////////
void print_horizontal_rule ()// 구분선 출력
{
	printf("============================\n");
}
//////////////////////////////////////////////////
void print_menu()//메뉴 보여주기
{
	printf("1) Insert\n2) Sort\n3) Quit\nSelect a menu : ");// : 옆에 입력이 보여야 하므로 \n 사용하지 않음.
}
//////////////////////////////////////////////////
int print_empty_file_sort()//현재 프로그램에 sort할 파일이 없을 경우에만 사용되어야 함. 중요한 것은 빈 파일에 대한 검사 로직은 따로 구현해야 함.
{
	printf("\nResult : There is no data to be sorted. Program terminates.\n");//sort할 데이터 없음 알림
	print_horizontal_rule();
	return 0;//프로그램 종료
}
//////////////////////////////////////////////////
int print_quit()//menu에서 3번이 입력될 경우 사용. 즉, '3번이 입력될 경우'에 대한 로직은 따로 구현
{
	print_horizontal_rule();
	return 0;//프로그램 종료
}
//////////////////////////////////////////////////
int print_error_yo()//나이오류가 결정났을 때 사용. 즉, 검사 로직은 따로 구현
{
	printf("Result : The age cannot be a negative number. Program terminates.\n");
	print_horizontal_rule();

	return 0;// 프로그램 종료
}
//////////////////////////////////////////////////
int print_error_sr(){//score range 벗어날 경우 사용. 즉, 검사 로직은 따로 구현
	printf("Result: The score is out of range. Program terminates.\n");
	return 0;//프로그램 종료
}
//////////////////////////////////////////////////
void print_sort_menu()//sort 메뉴 출력
{
	printf("1) Name\n2) Age\n 3) Math\n 4) English\n5) History\nChoose the field to sort by : ");//: 뒤에 입력을 받기 위해 \n 사용하지 않음.
}
//////////////////////////////////////////////////
int logic_of_2()//첫 메뉴 출력. 첫 메뉴 출력이므로 당연히 입력된 파일은 없음
{
	print_menu();//menu 출력
	scanf("%d", &menu_btn);//menu 입력 받아서 저장
	if (menu_btn == 2)
	{
		return print_empty_file_sort();//0을 반환하고 종료
	}
	else if (menu_btn == 3)
	{
		return print_quit();//0을 반환하고 종료
	}
	else if (menu_btn == 1)//menu 파일 입력
	{
		return 1; //1을 반환함으로써 3번 과정인 Input 받기를 실행함.
	}
}
//////////////////////////////////////////////////
int logic_of_3()//파일 받는 로직 구현
{
	printf("\nFile name : ");
	char file_name[50];//파일명 입력받기 위한 변수 선언
	scanf("%s",file_name);//파일이름 입력
	fp= fopen(file_name,"r");//파일 이름 찾아서 열기//추후 fclose로 닫아야 함.
	if (fp == NULL)//빈 파일 요구받아았을 경우 종료
	{
		return 0;
	}
	num_of_student=count_student(fp);//학생 수를 전역 변수에 저장
	rewind(fp);//파일 포인터 원위치로
	students = calloc(num_of_student, sizeof(struct student));//추후 free(students)로 해제해야 함.
	for (int count=0;count<num_of_student;count++)
	{
		fscanf(fp,"%s %d %d %d %d",students[count].name, &students[count].age, &students[count].math, &students[count].english, &students[count].history);
	}
}
//////////////////////////////////////////////////
int count_student(FILE *fp)
{
	int temp_count=0;//학생 수 세기 위한 변수 선언
	char temp_name[50];
	int temp_age, temp_math, temp_english, temp_history;
	while(fscanf(fp,"%s %d %d %d %d", temp_name, &temp_age, &temp_math, &temp_english, &temp_history) == 5){
		temp_count++;
	}
	return temp_count;
}
//////////////////////////////////////////////////
int logic_of_4()//파일 조건 검사: 나이가 자연수여야 하고, 성적이 0~100 범위 안에 있어야 함.
{
	for (int check_contidion=0;check_contidion<num_of_student;check_contidion++)
	{
		if (students[check_contidion].age < 0)
		{
			fclose(fp);
			free(students);
			return print_error_yo();
		}
		else if (students[check_contidion].math <0 || students[check_contidion].english <0 || students[check_contidion].history <0)
		{
			fclose(fp);
			free(students);
			return print_error_sr();
		}
		else if (students[check_contidion].math > 100 || students[check_contidion].english > 100 || students[check_contidion].history > 100)
		{
			fclose(fp);
			free(students);
			return print_error_sr();
		}
	}
	return 1;
}
//////////////////////////////////////////////////
void logic_of_5()//Result 출력으로 파일 내용 보여주기
{

}
//////////////////////////////////////////////////
void logic_of_6()//파일을 입력받았으니 sort를 선택할 수 있게 메뉴 출력
{

}
void logic_of_7()//sort 메뉴 출력 어떤 인자를 기준으로 오름차순 정렬할 것인지 설정
{

}
void logic_of_8()//sort 메뉴 입력. 어떤 인자를 기준으로 오름차순 정렬할 것인지 결정
{

}
void logic_of_9()//logic_of_6 로 feedback loop. 여기서 quit될 때까지 무한 반복해야 함.
{

}