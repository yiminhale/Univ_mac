#include <limits.h>
#include "Stack_Link.h"

/*
십진수를 이진수로 전환.
양수를 입력받으면 -> 이진수로 전환.
 */


int main()
{
	int input,input_copy;//선언
	printf("Enter a number: ");//출력
	scanf("%d",&input);//입력값 저장
	input_copy=input;
	Stack *pStack=CreateStack(INT_MAX);
	while (1)
	{
		if (input/2)//input을 2로 나눈 몫이 0이 아니라면
		{
			Push(pStack,input%2);//나머지 저장
		}
		else//몫이 0이된다면->나머지가 무조건 1이므로(입력이 0이어도 ㄱㅊ) 이것을 저장 후 이진수를 뽑아내야 함.
		{
			Push(pStack,input);
			break;
		}
		input=input/2;
	}

	printf("The binary number of %d: ",input_copy);
	for (int i = pStack->count;i;i--)
	{
		printf("%d",Pop(pStack));
	}
	putchar('\n');
	DestroyStack(pStack);
	return 0;
}