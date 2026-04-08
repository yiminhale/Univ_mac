#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

static inline void cleanStr(char str[]);

int main() {
	/*
	int d[13] = { 10,14,15,18,19,21,22,31,32,35,0,0,0 };
	int b[3] = { 55,17,33 };
	//b를 d에 삽입하기. 순서유지하면서.
	int size = sizeof(b) / sizeof(int);
	for (int i = 0; i < size; i++) {
		int idx = 0;
		while (d[idx]<b[i]) {
			idx++;
			if (d[idx]==0 || b[i]<d[idx]) {
				break;
			}
		}//10반환
		if (d[idx] == 0) {//끝이라면
			d[idx] = b[i];
		}
		else {
			for (int i = 12;idx<=i;i--) {
				d[i] = d[i - 1];
			}
			d[idx] = b[i];
		}
	}
	for (int i = 0;i<=12;i++) {
		printf("%d ", d[i]);
	}
	*/

	/*
	char str[] = "  Who  am     i. To be    or not to  be    ";
	cleanStr(str);
	*/

	/*
	char name[256] = { 0 };
	printf("give me a name: ");
	scanf("%s", name);
	FILE* fp = fopen(name, "w");
	if (fp == NULL) {
		printf("sth wrong!\n");
		return 0;
	}
	fclose(fp);
	*/

	/*
	short a = 4;
	short* pa = &a;
	float b = 3.1;
	float* pb = &b;
	printf("a= %d\n", a);
	printf("b= %f\n", b);
	printf("a= %d\n", *pa);
	printf("b= %f\n", *pb);
	printf("&a= %p\n",pa);
	printf("&b= %p\n", pb);
	*/

	/*
	a 의 주소
	3.1
	b의 주소
	5.3
	7.2
	*/

	/*
	함수 인자 관련해서 강의.
	*/
	
	return 0;
}

static inline void cleanStr(char str[]) {
	int len = (int)strlen(str);
	char rtn[1024] = { 0 };//반환값 배열 선언 및 초기화
	for (int i = 0;i<len;i++) {//각 배열 원소 순회
		if (str[i] == ' '&&str[i+1]==' ') {//두칸 빈칸이면 스킵
			continue;
		}
		else if (str[i] == ' ' && str[i + 1] != ' ') {//다음칸이 빈칸이 아니면
			char t[2] = { 0 };//2개짜리 배열 선언하고
			t[0] = str[i];//첫칸 빈칸만들고
			strcat(rtn, t);//붙이기
		}
		else {//일반 문자라면
			char t[2] = { 0 };//2칸 선언
			t[0] = str[i];//해당 문자로 채우고
			strcat(rtn, t);//붙이기
		}
	}
	printf("%s", rtn);
}