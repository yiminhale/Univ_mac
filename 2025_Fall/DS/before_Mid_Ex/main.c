#include "Func.h"

int main()
{
	FAR *pFAR = CreateQueue();//밖에서 선언
	Queue *current=NULL;//밖에서 선언
	cycle(pFAR, current);
}