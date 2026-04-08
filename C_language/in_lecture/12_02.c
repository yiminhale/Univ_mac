#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void flip(int* a, int size);
void toLower(char* str);

int main() {
	/*
	int a = 2;
	int* ap=&a;//포인터 변수 생성
	printf("%p\n", &ap);//poi 변수의 주소 출력.
	printf("%p",ap);//a 의 주소 출력
	*/

	/*
	int a = 3, * p;
	int b = 1;

	*p = a; printf("%d\n",*p);//error
	p = b;//error. type issue
	p = &b;
	*/

	/*
	int arr[7] = { 11,4,31,2,5,12,15 };//0~6
	int len = sizeof(arr) / sizeof(int);//7-->3번 해야 함. 8이라면 4번해야 함.
	flip(arr, len);
	for(int i = 0;i<len;i++)
	{
		printf("%d ", arr[i]);
	}
	*/
	char str[] = "abcesZzmwrlmAnersfdasaf";
	int apb[1024] = { 0 };
	int a = (int)strlen(str);
	printf("%d\n\n", a);
	toLower(str);
	for (int i = 0;i<strlen(str);i++) {
		apb[str[i]]++;
	}
	for (int i = 0; i < 26;i++) {
		printf("%c = %d\n",'a'+i,apb[i]);
	}

	/////////////lab 9 참고할 것.
	/*
	FILE* fp = fopen("hi.txt", "w");
	if (fp == NULL) {
		printf("input file wrong\n");
		return 0;
	}
	fprintf(fp, "Hello, this is ur name: yimin_hale\n");
	fclose(fp);
	*///파일포인터


	return 0;
}

void flip(int *arr,int size) {//size=7
	for (int i = 0;i<size/2;i++) {//0 1 2
		int temp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = temp;
	}
}

void toLower(char *str) {
	for (int i = 0;i<strlen(str);i++) {
		if (str[i] <= 'Z' && 'A' <= str[i]) {
			str[i] = str[i] + 'a' - 'A';
		}
	}
}