#define _CRT_SECURE_NO_WARNINGS
//#define debug
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int isNarcNum(int i,int result);
int ispld(int i);
int isqr(int n);
int str2num(char arr[]);
void dec2hexa(int n);

typedef struct Date {
	int Year;
	int Month;
	int Day;
}Date;

typedef struct Complex {
	double Real;
	double Imagine;
}Complex;

typedef struct NoteBook {
	int qq;
	char name[32];
	char phone[16];
}NoteBook;

Complex cal(Complex A, Complex B, int input);

int main() {
	/*
	for (int i = 100; i < 1000; i++) {
		int result = 0;
		result = isNarcNum(i, result);
		if (i == result) {
			printf("%d\n", i);
		}
	}
	*/
	/*
	printf("input int: ");
	int input;
	scanf("%d", &input);
	dec2hexa(input);
	*/

	/*
	Date* pDate = (Date*)calloc(1, sizeof(Date));
	printf("Year: ");
	scanf("%d", &pDate->Year);
	printf("Month: ");
	scanf("%d", &pDate->Month);
	printf("Day: ");
	scanf("%d", &pDate->Day);
	daycount(pDate);
	*/

	/*
	Complex A, B;
	printf("1st Vari Real : ");
	scanf("%lf", &A.Real);
	printf("1st Vari Imagine : ");
	scanf("%lf", &A.Imagine);
	printf("2nd Vari Real : ");
	scanf("%lf", &B.Real);
	printf("2nd Vari Imagine : ");
	scanf("%lf", &B.Imagine);
	printf("1: Add 2: Sub 3: Mul 4: Div");
	int input;
	scanf("%d", &input);
	Complex rtn = cal(A, B, input);
	printf("R: %lf, I: %lf\n", rtn.Real, rtn.Imagine);
	*/

	/*
	NoteBook arr[5];
	for (int i = 0; i < 5; i ++ ) {
		arr[i].qq = i+1;
		printf("%d.\n",arr[i].qq);
		printf("name: ");
		scanf("%s", arr[i].name);
		printf("phone #: ");
		scanf("%s", arr[i].phone);
	}
	*/

	int* freq = (int*)calloc(128, sizeof(int));
	printf("Input String: ");
	char i_arr[128];
	scanf("%s", i_arr);
	for (int i = 0;i<strlen(i_arr);i++) {
		int a = (int)i_arr[i];
		freq[a]++;
	}
	for (int t = 0; t < 128;t++) {
		if (freq[t]!=0)
		printf("%c : %d\n",t,freq[t]);
	}
	free(freq);
	//메인 종료
	return 0;
}

int isNarcNum(int i, int result){
	int temp = i / 10;
	int r = i - temp * 10;
	result += pow(r,3);
	if (temp == 0) {
		return result;
	}
	return isNarcNum(temp, result);
}

int ispld(int i) {//10201 //707 //1221
	int result = 0;
	int temp,diff;
	for (temp = i / 10 ; temp != 0; temp = temp / 10) {
		int r = i - temp * 10;
		result = result * 10 + r;
	}
	if (i == result) {
		return 1;
	}
	else {
		return 0;
	}
		
}

int isqr(int n) {
	if (sqrt(n)*sqrt(n)==n) {
		return 1;
	}
	else {
		return 0;
	}
}

int str2num(char arr[]) {
	int len = (int)strlen(arr);//312 -> 3
	int result = 0;
	for (int t = 0;t< (int)strlen(arr);t++) {//012
		result += (arr[t] - '0') * pow(10, len-1);
		//result = result*10 + arr[t]-'0';
		len--;
	}
	return result;
}

void dec2hexa(int n) {

	int Q = n / 16;
	int R = n % 16;
	if (Q) {
		dec2hexa(Q);
	}
	else if (!Q) {
		printf("0x");
	}
	switch (R) {
	case 10:printf("A"); break;
	case 11:printf("B"); break;
	case 12:printf("C"); break;
	case 13:printf("D"); break;
	case 14:printf("E"); break;
	case 15:printf("F"); break;
	}
	if (R<10) {
		printf("%d", R);
	}
}

int daycount(Date* pDate) {//날짜의 구조체를 입력받으면 그해의 몇 번째 날짜인지 계산.
	int sum = 0;
	int yoon=-1;
	/*
	 * 로직 설명.
	 * 입력받은 월의 전월까지는 모든 수를 센다. 여기서 윤년 체크해야 함.
	 * 해당 월의 일수까지는 그냥 더한다.
	 */
	if (pDate->Year%400==0) {//윤년임
		yoon=1;
	}
	else if (pDate->Year % 100 == 0) {//윤년 아님
		yoon=0;
	}
	else if (pDate->Year%4==0) {//윤년임.
		yoon=1;
	}
	else//나머지는 윤년 아님.
	{
		yoon=0;
	}
	if (pDate->Month==1)//1월이라면
	{
		sum=pDate->Day;
		return sum;
	}
	else if (pDate->Month<=12)//31: 1 3 5 7 8 10 12//30: 4 6 9 11//28: 2 //윤년일 경우 2월은 29일
	{
		for (int i=1;i<pDate->Month;i++)
		{
			if (i==1||i==3||i==5||i==7||i==8||i==10||i==12)
			{
				sum+=31;
			}
			else if (i==4||i==6||i==9||i==11)
			{
				sum+=30;
			}
			else if (yoon==1 && i==2)
			{
				sum+=29;
			}
			else
			{
				sum+=28;
			}
		}
		sum=sum+pDate->Day;
		return sum;
	}
}

Complex cal(Complex A, Complex B, int input) {
	Complex rtn;
	switch (input) {
	case 1:
		rtn.Real = A.Real + B.Real;
		rtn.Imagine = A.Imagine + B.Imagine;
		return rtn;
		break;
	case 2:
		rtn.Real = A.Real - B.Real;
		rtn.Imagine = A.Imagine - B.Imagine;
		return rtn;
		break;
	case 3:
		rtn.Real = A.Real * B.Real - A.Imagine * B.Imagine;
		rtn.Imagine = A.Imagine * B.Real + A.Real*B.Imagine;
		return rtn;
		break;
	case 4:
		B.Imagine = -1 * B.Imagine;
		Complex rtn = cal(A, B, 3);
		rtn.Imagine = rtn.Imagine / (pow(B.Real, 2) + pow(B.Imagine, 2));
		rtn.Real = rtn.Real / (pow(B.Real, 2) + pow(B.Imagine, 2));
		return rtn;
		break;
	}
	return rtn;
}
