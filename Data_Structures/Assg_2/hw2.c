/*
로직 설명
1. Input을 먼저 받음. "Input: "을 출력하고 사용자로부터 입력받아야 함.
    Input 조건:
    - 10개 정수로 이루어진 집합 2개를 입력받아야 함.
        구현방법: scanf를 두번 사용하고, 첫번째 scanf 끝에는 \n 사용해야 할듯. 
        오류처리: 첫번째 scanf든 두번째 scanf든 10개 정수가 아니라면, "You must input 2 sets of 10 numbers."를 출력해야 함.
            **중요** 10개정수도 아니고 오름차순도 아니라면, 이 오류를 우선해서 출력해야 함. 즉, "You should input 2 sets of 10 numbers."를 출력해야 함.
    - 각 집합은 오름차순이어야만 함
        입력 양식: -3, -1, 0, 1, 3, 6, 17, 20, 31, 71 이런식으로 10개의 정수가 콤마로 구분되어 입력받음
        로직: 이 각각의 수를 구분해서 길이가 10인 배열로 받고, 이 배열의 인덱스를 사용하여 arr[n]<arr[n+1] (n in Z+, n<9)인지 확인함.
        오류처리: 첫 번째 scanf든 두 번째 scanf든 오름차순이 아니라면, "The input numbers are not in ascending order."를 출력해야 함.


2. Output 출력
    두 집합의 모든 수를 합친 후 내림차순으로 콤마없이 띄워쓰기로 출력해야 함.
    e.g.) 215 213 212 211 210 120 111 100 50 30 19 9 8 6 4 3 2 1 -1
    - 같은 수는 한번만 출력되어야 함. 즉, 2가지 집합을 합쳤을 때 같은 수가 있다면, 이는 한 번만 출력되어야 한다는 의미.
sub condition: 반드시 Pointer와 Array 사용해야 함.
*/

#include <stdio.h> // 표준 입출력에 대한 헤더 파일
#include <stdlib.h>// 일반적인 함수들에 대한 헤더 파일
#include <string.h>// 문자열 처리 함수들에 대한 헤더 파일

int main() {
    printf("Input: \n"); //"Input :" 출력 및 줄바꿈
    int input_1st[11]={0};//10개를 초과하는 입력을 감지하기 위해 11로 선언하고, 모든 배열 0으로 초기화
    int result_1st = scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &input_1st[0], &input_1st[1], &input_1st[2], &input_1st[3], &input_1st[4], &input_1st[5], &input_1st[6], &input_1st[7], &input_1st[8], &input_1st[9], &input_1st[10]);
    //10개의 정수를 각 배열에 저장 완료하였음.
/*
첫 번째 입력받은 후 바로 Input 조건 검사해야 함.
1st: 10개의 정수를 받은게 맞는지 확인
    -정상적인 경우: [0]~[9]까지만 입력된 정수가 들어가고 나머지 [10]~[99]까지는 값이 0이어야 함.
    -비정상인 경우:
        1)10개 정수를 받지 못한 경우:
2nd: 오름차순인지 확인
*/
    if (result_1st != 10)
    {
        printf("You must input 2 sets of 10 numbers.\n");
        return 0;
    }
    //오름차순인지 확인
    for (size_t alpha = 9; alpha; --alpha)
    {
        if (input_1st[alpha-1] > input_1st[alpha])
        {
            printf("The input numbers are not in ascending order.\n");
            return 0;
        }
    }
////////////////////2번째 input
    int input_2nd[11]={0};//10을 초과하는 입력을 선별하기 위해 11로 선언하고, 모든 배열 0으로 초기화
    int result_2nd = scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &input_2nd[0],&input_2nd[1],&input_2nd[2], &input_2nd[3], &input_2nd[4], &input_2nd[5], &input_2nd[6], &input_2nd[7], &input_2nd[8], &input_2nd[9], &input_2nd[10]);
/*
두 번째 조건 검사.
*/
    if (result_2nd != 10)
    {
        printf("You must input 2 sets of 10 numbers.\n");
        return 0;
    }
    //오름차순인지 확인
    for (size_t beta = 9; beta; --beta)
    {
        if (input_2nd[beta-1] > input_2nd[beta])
        {
            printf("The input numbers are not in ascending order.\n");
            return 0;
        }
    }
////////////////////결과물 출력 파트
    printf("Output :\n");
/*
두개의 배열 합쳐야 함.
*/
    //////////////////// 변수 선언 부분
    int *ptr1 = input_1st;
    int *ptr2 = input_2nd;
    int total[20] = {0};
    int first = 9;
    int second = 9;
    int count = 0;
/////////////////////////로직 부분
    for (count = 0; first >= 0 || second >= 0 ; ++count )
    {
//first가 -1에 도달할 경우
        if (first == -1)
        {
            total[count] = ptr2[second];
            --second;
        }
//second가 -1에 도달할 경우
        else if (second == -1)
        {
            total[count] = ptr1[first];
            --first;
        }
//일반적인 시작은 여기부터
        else if (ptr1[first]>ptr2[second])
        {
            total[count] = ptr1[first];
            --first;
        }
        else if (ptr1[first]<ptr2[second])
        {
            total[count] = ptr2[second];
            --second;
        }
        else if (ptr1[first]==ptr2[second])
        {
            //input_1st에서 같은 수가 있을 경우
            while (ptr1[first]==ptr1[first-1]){
                --first;
            }
            //input_2nd에서 같은 수가 있을 경우
            while (ptr2[second]==ptr2[second-1]){
                --second;
            }
            total[count] = ptr1[first];
              --first;
              --second;
        }
    }
/////////////printf 부분
    for (size_t i = 0;i < count; ++i){
        printf("%d ", total[i]);
    }
    
    return 0;
}