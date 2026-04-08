#include <stdio.h>

int main(){
	int vari1;
	double vari2;
	char vari3;
	char vari4[50];

	printf("정수 입력: ");
	scanf("%d", &vari1);

	printf("소수 입력: ");
	scanf("%lf", &vari2);

	printf("단일문자 입력: ");
	getchar(); // 버퍼 비우기
	scanf("%c", &vari3);

	printf("문자열 입력: ");
	scanf("%s", vari4);

	printf("방금 입력된 변수들을 출력한다. 정수: %d, 소수: %lf, 단일문자: %c, 문자열: %s\n", vari1, vari2, vari3, vari4);
	//////////////////////putchar, getchar
	putchar('A');//일반 입력
	putchar('\n');//줄바꿈
	putchar('B');//일반 입력
	putchar('\n');//줄바꿈
	getchar();//버퍼 제거 -> 문자열 입력 부분 scanf에 남아있던 버퍼를 제거함. 매우 중요.
	printf("단일 문자 입력: ");
	int vari5 = getchar();//앞서 버퍼가 정상적으로 제거되었다면, 정상 진행됨.
	putchar(vari5);// 값 다시알려줌
	putchar('\n');//줄바꿈
	int vari6=0;//변수선언 및 초기화
	printf("정수 입력: ");//
	scanf("%d",&vari6);//
	printf("vari6: %d\n", vari6);
	getchar();//앞서 받은 scanf에 남아있던 \n 제거//
	printf("getchar()에 들어갈 부분을 입력하시오: ");
	int vari7 = getchar();//만약 37번째 줄의 주석이 맞다면, 정상 진행됨.
	putchar(vari7);//값반환
	return 0;
}