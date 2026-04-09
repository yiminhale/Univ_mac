#ifndef ASSG_9_SORTING_H
#define ASSG_9_SORTING_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

// arr= 정렬할 배열
// n: 배열의 길이

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int arr[],int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void selection_sort(int arr[],int n) {//벽 뒤에서 제일 작은놈 벽 바로 앞과 스왑
    for (int i = 0; i < n - 1; i++) {//마지막은 자동 정렬되니까.
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(&arr[i], &arr[min_idx]);
    }
}

void insertion_sort(int arr[],int n) {//벽 바로 뒤에 있는애 벽 앞에 적절한 위치에 삽입
    for (int i = 1; i < n; i++) {//첫 애는 이미 정렬되어 있으니까 두번째 애부터 마지막까지.
        int key = arr[i];//키는 벽에 있는 친구.
        int j = i - 1;//벽 앞에서 맨 앞까지 이동하면서 자리찾기.
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];//오른쪽으로 복사
            j--;
        }
        arr[j + 1] = key;//이자리에 삽입.
    }
}

void bubble_sort(int arr[],int n) {
    for (int i = 0; i < n - 1; i++) {//마지막은 자동정렬
        for (int j = 0; j < n - i - 1; j++) {//갈수록 뒤에는 실행하지 않아도 됨.
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

int partition(int arr[],int n,int low, int high) {//파티션 방법. 파티션 방법도 각기 다름
    int pivot = arr[high];//변경될 수 있음.
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sort_rec(int arr[],int n,int low, int high) {
    if (low < high) {
        int pi = partition(arr,n,low, high);
        quick_sort_rec(arr,n,low, pi - 1);
        quick_sort_rec(arr,n,pi + 1, high);
    }
}

void quick_sort(int arr[],int n) {
    quick_sort_rec(arr,n,0, n - 1);
}

void merge_arrays(int arr[],int n,int left, int mid, int right) {
    int temp[MAX];
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];

    for (i = 0; i < k; i++)
        arr[left + i] = temp[i];
}

void merge_sort_rec(int arr[],int n,int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort_rec(arr,n,left, mid);
        merge_sort_rec(arr,n,mid + 1, right);
        merge_arrays(arr,n,left, mid, right);
    }
}

void merge_sort(int arr[],int n) {
    merge_sort_rec(arr,n,0, n - 1);
}

#endif //ASSG_9_SORTING_H