#include <limits.h>
#include "Stack_Link.h"
/*
구현 내용
- Ctrl+d가 눌려지면 입력 종료//EOF임.
- 스택 사이즈 결정 문제
 */
int main()
{
	Stack *pStack=CreateStack(INT_MAX);//일단 최대 크기로 생성
	while (1)
	{
		printf("Enter a number: <Ctrl+d> to stop: ");
		Element item = 0;
		int brk = scanf("%d",&item);
		if (brk==EOF)
		{
			putchar('\n');
			break;
		}
		Push(pStack,item);
	}

	printf("The List of numbers reversed: \n");//안내 문구
	for (int i=pStack->count;i;i--)
	{
		printf("%d\n", Pop(pStack));
	}
	DestroyStack(pStack);
	return 0;
}