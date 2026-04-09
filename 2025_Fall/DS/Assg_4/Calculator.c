/*
- 괄호 포함하는 사칙연산을 수행하는 계산기 소스코드: Calculator.c
	- [ ]  양의 정수 받음 --ㅇㅋ
	- [ ]  token으로 분석(빈칸으로 구분이 안 되는 붙은 식도 분석 가능해야 함. C에서 제공하는 token 분석하는 함수도 있음.) --ㅇㅋ
	- [ ]  빈칸 있을 수 있음 --ㅇㅋ
	- [ ]  괄호 있을 수 있음 --ㅇㅋ
	- [ ]  두자리 이상의 수도 처리 가능해야 함.
	- [ ]  식의 계산 결과는 양수로 가정(음수, 분수 처리 없음)
	- [ ]  Infix → postfix로 변환해야 함.
	- [ ]  수식의 유효성 검사 수행해야 함. e.g. 괄호 열기만 하고 닫지 않았다던지, 이항연산식을 표현한 건지 등. --완료
	- [ ]  이 문제를 위해 Stack_Array.h와 Stack_Link.h를 변형해야 한다면, 변형된 버전은 Stack_Array2.h, Stack_Link2.h 로 이름지어서 활용해야 함.
 */
#include <limits.h>
#include <stddef.h>
#include "Stack_Link2.h"//char 버전
#include "Stack_Array2.h"//int 버전: 계산용도로 함수명 수정.
#include <string.h>
int main()
{
	printf("Arithmetic Expression : ");//출력
	char input[1024];//저장할 배열 선언
	scanf("%[^\n]",input);//입력받기 //띄워쓰기 받아야 함.
	////////////////////////////////////////////////////////조건 검사
	/*
	 바로 조건 검사. Infix 상태에서 접근
	 1. 괄호 개수 맞는지.
	 2. 피연산자, 연산자 올바르게 배치되어 있는지.
	*/
	//////////////////////////////////////////괄호 개수 세기
	int left_parent=0,right_parent=0;//괄호 개수 저장 변수 선언 및 0으로 초기화
	char *poi_left=strstr(input,"(");//왼쪽 괄호가 있다면 그 주소값 반환, 없다면 NULL값 반환.
	while (poi_left!=NULL)//왼쪽 괄호가 있다면
	{
		left_parent++;//갯수 하나 추가하고,
		poi_left = strstr(poi_left+1,"(");//다음 왼쪽 괄호 위치를 찾고 있다면 그 위치의 메모리 주소를 저장해라. 없다면 NULL을 받아라.
	}

	char *poi_right = strstr(input,")");
	while (poi_right!=NULL)
	{
		right_parent++;
		poi_right=strstr(poi_right+1,")");
	}
	if (left_parent!=right_parent)//괄호 개수 다를 경우 에러 출력 후 종료.
	{
		printf("Error : Check the pairs of Parenthesis!\n");
		return 0;
	}
	//////////////////////////////////////////이항연산식 확인
	///operator part
	char *poi_operator_copy;//연산자로 시작하는지 체크하기 위해 복사본 선언

	char *poi_operator=poi_operator_copy =strpbrk(input,"+-*%");//operator 확인후 그 주소 저장. //이 부분은 널이 될 수 없음. 계산기니까.
	char *poi_operator_next = strpbrk(poi_operator+1,"+-*%");//그 다음 위치 operator 찾기. //이 부분은 널이 될 수 있음.
	char *poi_check_operand = strpbrk(poi_operator+1,"0123456789");//숫자는 언제 나오는지
	while (poi_operator_next!=NULL)
	{
		if (poi_check_operand!=NULL &&poi_operator_next<poi_check_operand)//연산자 연산자 숫자 -> 오류
		{
			printf("Error : Check the binary expression! by operator 1\n");//오류 로그 출력
			return 0;//종료
		}
		else
		{
			poi_operator = poi_operator_next;//poi op는 poi op next가 되고
			poi_operator_next = strpbrk(poi_operator+1,"+-*%");//poi op next는 그 다음 연산자 위치를 찾아야 함. 없으면 NULL
			poi_check_operand = strpbrk(poi_operator+1,"0123456789");//poi check는 다음 피연산자를 찾아야 함.
		}
	}
	///operand part
	char *poi_operand = strpbrk(input,"0123456789");//피연산자 주소 //계산기 상 널이 될 수 없음.
	char *poi_operand_next = strpbrk(poi_operand+1,"0123456789");//다음 피연산자 주소 //널이 될 수 있음.
	char *poi_check_operator = strpbrk(poi_operand+1,"+-*%");//연산자 주소 //널이 될 수 있음.
	char *poi_check_space = strpbrk(poi_operand+1," ");//띄워쓰기 주소 //널이 될 수 있음.
	if (poi_operator_copy<poi_operand)//연산자로 시작한다면:
	{
		printf("Error : Check the binary expression! by operator 3\n");//오류 로그 출력
		return 0;//종료
	}
	while (poi_operand_next!=NULL)//다음 피연산자가 없을 경우 스탑.
	{//space, operator는 null이 아니여야 함.
		if (poi_operand+1==poi_operand_next)//숫자 바로 옆에 숫자가 있는 경우-> 두자릿 수 이상이므로 정상
		{
			;//아무것도 하지마
		}
		else if (poi_check_operator!=NULL && poi_check_space!=NULL&&poi_check_space<poi_operand_next && poi_operand_next < poi_check_operator)//띄워쓰기 숫자 연산자 -> 오류임.
		{
			printf("Error : Check the binary expression! by opearand\n");
			return 0;
		}
		poi_operand=poi_operand_next;
		poi_operand_next = strpbrk(poi_operand+1,"0123456789");
		poi_check_operator = strpbrk(poi_operand+1,"+-*%");
		poi_check_space = strpbrk(poi_operand+1," ");
	}
	///////////////////////////////////////////////////////토큰화 시작
	printf("Input : %s\n",input);// 입력값 그대로 출력

	Stack *pStack = CreateStack(INT_MAX);//저장할 스택 생성후 스택의 주소 pStack에 저장
	/*
	 *토큰화 및 Stack에 바로 저장 후 postfix로 고치기
	 *
	 *각 요소를 기준으로 잘라서
	 *postfix로 바꾸는 stack 연산을 수행한 후
	 *뱉어내야 함.
	 *
	 * 띄워쓰기를 제거해야 함.
	 * 문자열의 문자를 정수로 전환해야 함.
	 *
	 * post fix 규칙:
	 *	우선순위가 높은 연산자는 쌓을 수 있다.
	 *	우선순위가 같거나 낮은 연산자는 자기보다 우선순위가 낮은 연산자를 받을 때까지 pop시킨 후 push한다.
	 *	괄호가 닫히면 괄호가 시작된 부분까지 pop한다. 괄호는 postfix에서 출력되지 않는다.
	 *
	 *	예시: 3 * ( ( 67 - 60)*4 - 20 ) \0까지 합쳐서 26개.
	 */
	for (int i = 0;i<strlen(input);i++)//공백 제거
	{
		if (input[i]==' ')//해당 문자열 칸이 공백이라면
		{
			for (int j=i;j<strlen(input);j++)
			{
				input[j]=input[j+1];//
			}
		}
	}
	//input == 3*((67-60)*4-20) 인 상태.
	////////////////////////////////////////////////////////Postfix로 고치기
	char postfix[1024]="";
	/*순서
	 *숫자는 postfix에 붙고
	 *연산자는 stack으로 올라가야 함.
	 *pop되면 내려와서 postfix에 붙어야 함.
	 */
	//input == 3*((67-60)*4-20) 인 상태.
	int post_len=0;//postfix 길이 저장 변수 선언 및 초기화
	for (int i = 0;i<=strlen(input);i++)
	{
		if (input[i]>='0' &&input[i]<='9' && input[i+1]>='0'&&input[i+1]<='9')//두자릿수 이상 이라면
		{
			postfix[post_len++]=input[i];
			postfix[post_len]='\0';
		}
		else if (input[i]>='0'&&input[i]<='9')//한 자릿수 숫자라면
		{
			//postfix에 추가해야 함.
			postfix[post_len++]=input[i];//postfix를 숫자로 채움
			postfix[post_len++]=' ';//띄워쓰기로 구분
			postfix[post_len]='\0';//끝을 늘려줘야 함.
		}
		else if (input[i]=='(')//좌괄호라면
		{
			Push(pStack,input[i]);//push
		}
		else if (input[i]==')')//우괄호라면
		{
			/*postfix[i]=Pop(pStack);*///pop해야 함. 좌괄호를 만날때까지. 그리고 좌괄호는 버려야 함.
			while (!IsEmptyStack(pStack)&&Top(pStack)!='(')//Top이 좌괄호가 아니라면 pop해야 함. ->좌괄호를 만나면 스탑
			{
				postfix[post_len++]=Pop(pStack);
				postfix[post_len]='\0';
			}
			if (!IsEmptyStack(pStack)&&Top(pStack)=='(')//좌괄호를 만나면
			{
				Pop(pStack);//좌괄호 공중에 날리기
			}
		}
		else if (input[i]=='+'||input[i]=='-')//+ - 연산자라면
		{
			while (!IsEmptyStack(pStack)&&(Top(pStack)=='*'||Top(pStack)=='%'||Top(pStack)=='+'||Top(pStack)=='-'))//top이 자기보다 우선순위가 높거나 같다면
			{
				postfix[post_len++]=Pop(pStack);//pop해서 postfix에 삽입해야 함.
				postfix[post_len]='\0';//끝 늘려주기
			}
			if (IsEmptyStack(pStack)||Top(pStack)=='(')//top이 좌괄호 혹은 비어있을 경우
			{
				Push(pStack,input[i]);//push
			}
		}
		else if (input[i]=='*'||input[i]=='%')// *, / 연산자라면
		{
			if (IsEmptyStack(pStack)||Top(pStack)=='+'||Top(pStack)=='-'||Top(pStack)=='(')//Top이 +, -, ( 라면 혹은 스택이 비어있다면
			{
				Push(pStack,input[i]);//push할것.
			}
			else if (Top(pStack)=='*'||Top(pStack)=='%')//top에 *, % 연산자가 있다면
			{
				postfix[post_len++]=Pop(pStack);//빼내고
				postfix[post_len]='\0';//길이늘린다음
				Push(pStack,input[i]);//push할것.
			}
		}
		else if (input[i]=='\0')// \0이라면 -> 끝임: 스택에 남아있던 연산자를 모두 pop해서 postfix에 붙이기.
		{
			while (!IsEmptyStack(pStack))
			{
				postfix[post_len++]=Pop(pStack);
				postfix[post_len]='\0';
			}
			DestroyStack(pStack);//스택 해제
		}
	}//for종료
	printf("Post : %s\n",postfix);//출력
	//postfix=3 67 60 -4 *20 -* 인 상태.
	////////////////////////////////////////////////////////Postfix를 사용하여 계산하기
	Stack_INT *iStack=CreateStack_INT(INT_MAX);//계산할 스택 생성
	for (int i=0;i<=strlen(postfix);i++)//앞에서부터 읽으면서 계산진행해야 함.
	{
		if (postfix[i]>='0'&&postfix[i]<='9'&&postfix[i+1]>='0'&&postfix[i+1]<='9')//두자릿수 이상 정수라면
		{
			//' ' 가 나올때까지 읽고 정수로 바꿔야 함. 그리고 push 해야 함.
			Push_INT(iStack,atoi(postfix+i));
			//몇자리 정수인지에 따라 달라지는데... n자리라면 여기서 n-1 만큼 i 증가시켜줘야 함.
			while (postfix[i]>='0'&&postfix[i]<='9')//빈칸 나올때까지
			{
				i++;//i 증가시켜라
			}
			i--;//순회하면서 1 증가하니까 하나 빼주기.
		}
		else if (postfix[i]>='0'&&postfix[i]<='9')//한 자릿수 정수라면
		{
			// 정수로 바꿔야 함.
			Push_INT(iStack,atoi(postfix+i));//push 해야 함.
		}
		else if (postfix[i]==' ')//공백이라면 패스해야 함.
		{
			;
		}
		else if (postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='*'||postfix[i]=='%')//연산자라면
		{
			int operand_2nd=Pop_INT(iStack);//먼저 빠지는 놈이 2번째 피연산자
			int operand_1st=Pop_INT(iStack);//두번째로 빠지는 놈이 첫번째 피연산자.
			switch (postfix[i])
			{
			case '+': Push_INT(iStack,operand_1st+operand_2nd);break;
			case '-': Push_INT(iStack,operand_1st-operand_2nd);break;
			case '*': Push_INT(iStack,operand_1st*operand_2nd);break;
			case '%': Push_INT(iStack,operand_1st%operand_2nd);break;
			}
		}
		else if (postfix[i]=='\0')// 끝이라면,
		{
			printf("Result : %d\n",Pop_INT(iStack));

		}
	}
	DestroyStack_INT(iStack);
	return 0;
}//메인 종료