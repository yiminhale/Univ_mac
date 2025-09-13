/* ptr_swap1.c */
#include <stdio.h>

void pswap(int *p1, int *p2)
{
    printf("스왑 전 - p1: %d, p2: %d\n", *p1, *p2);
    int *temp;
    temp = p1;
    p1 = p2;
    p2 = temp;
    printf("스왑 후 - p1: %d, p2: %d\n", *p1, *p2);
}

int main(void)
{
    int A = 10, B = 20;
    int *pA, *pB;
    pA = &A;
    pB = &B;

    pswap(pA, pB);

    // 함수 호출 후
    printf("pA가 가리키는 변수 : %d \n", *pA);
    printf("pB가 가리키는 변수 : %d \n", *pB);
    return 0;
}