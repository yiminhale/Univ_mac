#include <stdio.h>

// swap 함수: int 포인터 2개를 받음
void swap(int* a, int* b) {
    int temp = *a;   // *a: 단일 포인터 역참조 (int 값)
    *a = *b;
    *b = temp;
}

// 배열을 받는 함수 - 방법 1
void test1(int arr[], int size) {
    printf("\n=== test1: int arr[] 파라미터 ===\n");
    printf("arr의 타입: int* (포인터!)\n");
    printf("arr[0] 접근: %d\n", arr[0]);  // 배열 표기법
    printf("*arr 접근: %d\n", *arr);       // 포인터 표기법 (동일!)
    printf("arr[1] 접근: %d\n", arr[1]);
    printf("*(arr+1) 접근: %d\n", *(arr+1)); // 동일!
}

// 배열을 받는 함수 - 방법 2 (위와 완전 동일)
void test2(int* arr, int size) {
    printf("\n=== test2: int* arr 파라미터 ===\n");
    printf("arr의 타입: int* (포인터!)\n");
    printf("arr[0] 접근: %d\n", arr[0]);  // 배열 표기법 가능!
    printf("*arr 접근: %d\n", *arr);       // 포인터 표기법
}

// swap을 사용하는 flip 함수
void flip(int arr[], int size) {
    printf("\n=== flip 함수 ===\n");
    for (int i = 0; i < size/2; i++) {
        printf("swap(&arr[%d], &arr[%d])\n", i, size-1-i);

        // arr[i]는 int 타입 값
        // &arr[i]는 int* 타입 (주소)
        swap(&arr[i], &arr[size - 1 - i]);  // ← & 하나만!
    }
}

// 직접 swap하는 버전 (swap 함수 없이)
void flip_manual(int arr[], int size) {
    printf("\n=== flip_manual 함수 ===\n");
    for (int i = 0; i < size/2; i++) {
        // arr은 포인터이지만, arr[i]는 int 값
        int temp = arr[i];           // arr[i]: int 타입
        arr[i] = arr[size - 1 - i];  // 배열 접근 가능!
        arr[size - 1 - i] = temp;
    }
}

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};

    printf("========================================\n");
    printf("Q1. 배열 원소끼리 바꿀 때 * vs **?\n");
    printf("========================================\n");

    printf("\n배열: {10, 20, 30, 40, 50}\n");
    printf("\n[중요!] 표기법 설명:\n");
    printf("  numbers[0]   → int 타입 (값: 10)\n");
    printf("  &numbers[0]  → int* 타입 (주소)\n");
    printf("  *&numbers[0] → int 타입 (값: 10, 원래대로)\n");

    printf("\nswap 함수 시그니처: void swap(int* a, int* b)\n");
    printf("  - 파라미터가 int* 이므로 int의 주소를 받음\n");
    printf("  - 호출: swap(&numbers[0], &numbers[1])\n");
    printf("  - & 하나만! (int* 타입 전달)\n");
    printf("  - 함수 내부에서 *a로 값 접근 (단일 역참조)\n");

    printf("\n실제 swap 실행:\n");
    printf("Before: numbers[0]=%d, numbers[1]=%d\n", numbers[0], numbers[1]);
    swap(&numbers[0], &numbers[1]);  // ← & 하나만!
    printf("After:  numbers[0]=%d, numbers[1]=%d\n", numbers[0], numbers[1]);

    printf("\n\n========================================\n");
    printf("Q2. 함수에서 배열 받을 때 a[t] 접근?\n");
    printf("========================================\n");

    test1(numbers, 5);
    test2(numbers, 5);

    printf("\n[핵심!] 함수 파라미터로 배열을 받으면:\n");
    printf("  - int arr[]와 int* arr은 완전히 동일!\n");
    printf("  - 둘 다 포인터로 받음\n");
    printf("  - arr[i]로 접근 가능 (arr은 포인터지만!)\n");
    printf("  - arr[i] == *(arr+i) (동일한 표현)\n");

    printf("\n\n========================================\n");
    printf("실전 예제: 배열 뒤집기\n");
    printf("========================================\n");

    int test[5] = {1, 2, 3, 4, 5};
    printf("\nBefore flip: ");
    for (int i = 0; i < 5; i++) printf("%d ", test[i]);

    flip(test, 5);

    printf("\nAfter flip:  ");
    for (int i = 0; i < 5; i++) printf("%d ", test[i]);
    printf("\n");

    printf("\n\n========================================\n");
    printf("포인터 레벨 요약\n");
    printf("========================================\n");
    printf("int value = 10;          // 정수 값\n");
    printf("int* ptr = &value;       // 정수의 주소 (1단계 포인터)\n");
    printf("int** pptr = &ptr;       // 포인터의 주소 (2단계 포인터)\n");
    printf("\n");
    printf("배열 swap의 경우:\n");
    printf("  arr[i]는 int\n");
    printf("  &arr[i]는 int* ← swap에 전달\n");
    printf("  swap 내부에서 *a로 접근 (int로 역참조)\n");
    printf("  ** 필요 없음! (2단계 포인터 아님)\n");

    return 0;
}
