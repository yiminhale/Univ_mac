#include <stdio.h>

int main()
{
    int input_1st[100]={0};
    int result = scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &input_1st[0], &input_1st[1], &input_1st[2], &input_1st[3], &input_1st[4], &input_1st[5], &input_1st[6], &input_1st[7], &input_1st[8], &input_1st[9], &input_1st[10]);
    printf("%d", result);
}