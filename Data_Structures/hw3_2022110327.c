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
#include <string.h>
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
int logic_of_6();//파일 input 이후 메뉴 출력 및 로직
void logic_of_7();//sort 메뉴 단순 출력
void logic_of_8();//sort 메뉴 입력. 어떤 인자를 기준으로 오름차순 정렬할 것인지 결정
//굳이 필요 없을 듯. void logic_of_9();//logic_of_6 로 feedback loop. 여기서 quit될 때까지 무한 반복해야 함.
void sorting_algorithm(int btn_temp);//sorting을 처리하는 함수
/////////////////////////////////////////////////전역변수 선언
int menu_btn = 0;//menu 선택값을 위한 변수 선언 및 초기화
int num_of_student=0;
struct student *students=NULL;
FILE *fp=NULL;
int sort_menu_btn = 0;//sort menu 선택 저장 변수
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
		logic_of_3();//3번 과정. Input 받기.//문제될 경우 return 제거.
	}
	else if (result_of_2==0)//파일이 입력되지 않은 상태에서 3번과 2번을 선택할 경우.
	{
		return 0;//프로그램 종료
	}
	int result_of_4=logic_of_4();//4번 과정. 조건 검사. 만약 오류 발생할경우 return 0; 가 입력되면 프로그램 종료.
	if (result_of_4==1)//조건 검사를 통과한다면
	{
		logic_of_5();//파일의 결과를 출력하세요.
	}
	else if (result_of_4==0)//파일의 조건이 문제가 있을 경우
	{
		return 0;//프로그램 종료
	}
	int result_of_6=0;//logic_of_6가 반복되는 동안 계속 선언되는 것을 회피하기 위해 먼저 선언함.
	while (1)//파일이 입력된 상태에서는 3번 메뉴인 quit을 실행하기 전까지는 Insert든 Sort든 반복할 수 있어야 함.
	{
		result_of_6 = logic_of_6();
		if (result_of_6 == 0)//3번 Quit을 선택할 경우 프로그램 종료
		{
			break;
		}
		//2번 선택시 logic_of_6(); 함수 구성에 따라 sorting_algorithm(); 실행됨.
		//1번 선택시 logic_of_3(); 로 feedback하여 반복.
	}
	return 0;//프로그램 종료
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
	print_horizontal_rule();
	return 0;//프로그램 종료
}
//////////////////////////////////////////////////
void print_sort_menu()//sort 메뉴 출력
{
	printf("1) Name\n2) Age\n3) Math\n4) English\n5) History\nChoose the field to sort by : ");//: 뒤에 입력을 받기 위해 \n 사용하지 않음.
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
	printf("\nFile name : ");//일반 출력: ui용
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
		//각 구조체 변수에 txt 데이터 저장
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
		if (students[check_contidion].age <= 0)
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
	printf("Result :\n");//일반 출력
	printf("No Name Math English History\n");//일반 출력
	for (int index = 0; index<num_of_student;++index)
	{
		printf("%d %s %d %d %d %d\n",index+1,students[index].name,students[index].age,students[index].math,students[index].english,students[index].history);
	}
}
//////////////////////////////////////////////////
int logic_of_6()//파일을 입력받았으니 sort를 선택할 수 있게 메뉴 출력
{
	print_menu();
	scanf("%d", &menu_btn);//menu 입력 받아서 저장
	if (menu_btn == 2)//sort 선택.
	{
		logic_of_7();//sort 메뉴 단순 출력
		logic_of_8();//sort 메뉴 입력 및 진행
		return 1;//logic_of_6의 결과가 1이 됨.
	}
	else if (menu_btn == 3)//quit이므로 종료해야 함.
	{
		fclose(fp);
		free(students);
		return print_quit();//메모리를 누수를 방지하기 위해 해제하고 0을 반환하고 종료
	}
	else if (menu_btn == 1)//파일 재입력
	{
		fclose(fp);//이전 파일 메모리 해제
		free(students);//이전 파일 메모리 해제
		logic_of_3();//3번 과정으로 feedback 해야 함.
		int result_of_4_reuse=logic_of_4();//4번 과정. 조건 검사. 만약 오류 발생할경우 return 0; 가 입력되면 프로그램 종료.
		if (result_of_4_reuse==1)//조건 검사를 통과한다면
		{
			logic_of_5();//파일의 결과를 출력하세요.
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
//////////////////////////////////////////////////
void logic_of_7()//sort 메뉴 단순 출력
{
	print_sort_menu();
}
//////////////////////////////////////////////////
void logic_of_8()//sort 메뉴 입력. 어떤 인자를 기준으로 오름차순 정렬할 것인지 결정
{
	scanf("%d",&sort_menu_btn);//sort menu 에서 1~5까지 숫자를 받아서 전역변수에 저장
	sorting_algorithm(sort_menu_btn);//sorting 진행
}
//////////////////////////////////////////////////
/*void logic_of_9()//logic_of_6 로 feedback loop. 여기서 quit될 때까지 무한 반복해야 함.
{

}*/ //굳이 9번과정을 새로 만들 필요 없이 logic_of_6를 재활용하면 될듯.
//////////////////////////////////////////////////
void sorting_algorithm(int btn_temp)//sorting을 처리하는 함수
{	//num_of_student 를 사용해서 해당 횟수만큼 정렬 후 출력해야 함.
	//bubble sort로 접근.
	if (btn_temp ==1)//Name. 알파벳 순 정렬해야 함.
	{
		printf("No Name Age Math English History\n");
		//strcmp() 사용해서 접근//<string.h> call
		struct student temp;// 임시 구조체 변수 선언
		for (int i=num_of_student-1; i>0; --i)//학생 수-1 만큼 실행된다.
		{
			for (int j =0;j<i;++j)//i 만큼 실행된다.
			{
				if (strcmp(students[j].name,students[j+1].name)>0)
				{
					temp = students[j];
					students[j] = students[j+1];
					students[j+1] = temp;
				}
			}
		}//정렬은 종료. 이제 출력해야 함.
		for (int i = 0;i<num_of_student;++i)
		{
			printf("%d %s %d %d %d %d\n",i+1, students[i].name, students[i].age, students[i].math, students[i].english, students[i].history);
		}
	}
	else if (btn_temp==2)//age. 숫자 오름차순 정렬해야 함.
	{
		printf("No Age Name Math English History\n");//제목 행 출력
		struct student temp;// 임시 구조체 변수 선언
		for (int i=num_of_student-1; i>0; --i)//학생 수-1 만큼 실행된다.
		{
			for (int j =0;j<i;++j)//i 만큼 실행된다.
			{
				if (students[j].age > students[j+1].age)
				{
					temp = students[j];
					students[j] = students[j+1];
					students[j+1] = temp;
				}
			}
		}//정렬은 종료. 이제 출력해야 함.
		for (int i = 0;i<num_of_student;++i)
		{
			printf("%d %d %s %d %d %d\n",i+1, students[i].age, students[i].name, students[i].math, students[i].english, students[i].history);
		}
	}
	else if (btn_temp==3)//math. 숫자 오름차순 정렬해야 함.
	{
		printf("No Math Name Age English History\n");
		struct student temp;// 임시 구조체 변수 선언
		for (int i=num_of_student-1; i>0; --i)//학생 수-1 만큼 실행된다.
		{
			for (int j =0;j<i;++j)
			{
				if (students[j].math > students[j+1].math)
				{
					temp = students[j];
					students[j] = students[j+1];
					students[j+1] = temp;
				}
			}
		}//정렬은 종료. 이제 출력해야 함.
		for (int i = 0;i<num_of_student;++i)
		{
			printf("%d %d %s %d %d %d\n",i+1, students[i].math, students[i].name, students[i].age, students[i].english, students[i].history);
		}
	}
	else if (btn_temp==4)//english. 숫자 오름차순 정렬해야 함.
	{
		printf("No English Name Age Math History\n");
		struct student temp;// 임시 구조체 변수 선언
		for (int i=num_of_student-1; i>0; --i)//학생 수-1 만큼 실행된다.
		{
			for (int j =0;j<i;++j)
			{
				if (students[j].english > students[j+1].english)
				{
					temp = students[j];
					students[j] = students[j+1];
					students[j+1] = temp;
				}
			}
		}//정렬은 종료. 이제 출력해야 함.
		for (int i = 0;i<num_of_student;++i)
		{
			printf("%d %d %s %d %d %d\n",i+1, students[i].english, students[i].name, students[i].age, students[i].math, students[i].history);
		}
	}
	else if (btn_temp==5)//history. 숫자 오름차순 정렬해야 함.
	{
		printf("No History Name Age Math English\n");
		struct student temp;// 임시 구조체 변수 선언
		for (int i=num_of_student-1; i>0; --i)//학생 수-1 만큼 실행된다.
		{
			for (int j =0;j<i;++j)
			{
				if (students[j].history > students[j+1].history)
				{
					temp = students[j];
					students[j] = students[j+1];
					students[j+1] = temp;
				}
			}
		}//정렬은 종료. 이제 출력해야 함.
		for (int i = 0;i<num_of_student;++i)
		{
			printf("%d %d %s %d %d %d\n",i+1, students[i].history, students[i].name, students[i].age, students[i].math, students[i].english);
		}
	}
}
//////////////////////////////////////////////////