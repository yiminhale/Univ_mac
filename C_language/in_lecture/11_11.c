#define _CRT_SECURE_NO_WARNINGS
//#define debug
#include <stdio.h>

float max3(float a,float b, float c);
int gcd(int a, int b);
int isPrime(int a);
void insert(int n,int a[]);
void sorting(int a[]);

int main() {
	/*
	float a, b, c ;
	printf("input 1st : ");
	scanf("%f",&a);
	printf("input 2nd : ");
	scanf("%f",&b);
	printf("input 3rd : ");
	scanf("%f",&c);
	float output = max3(a, b, c);
	printf("%f", output);
	*/

	/*
	int a, b;
	printf("input 1st: ");
	scanf("%d",&a);
	printf("input 2nd: ");
	scanf("%d", &b);
	printf("%d", gcd(a, b));
	*/

	/*
	int a;
	printf("input #: ");
	scanf("%d", &a);
	printf("%d\n", isPrime(a));
	*/

	/*
	int a[10] = {3, 21, 5, 8,5,11,22,14,9,51};//0 1 2 3 4// 5 //6 7 8 9 10
	for (int i = 0;i<10/2;i++) {
		int temp = a[i];
		a[i] = a[9 - i];
		a[9 - i] = temp;
	}//�յ� �ٲٱ� ����
	for (int i = 0; i<10;i++) {
		printf("%d ",a[i]);
	}//���
	*/

	/*
	int n;
	printf("how many times: ");
	scanf("%d", &n);
	int a[1024];
	for (int i = 0; i < n;i++) {
		printf("%d�� �Է�: ", i);
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n;i++) {
		printf("%d ", a[i]);
	}
	*/

	/*
	int a[7] = { 3,14,15,18,22,35 };
	printf("what # u want to input: ");
	int b;
	scanf("%d", &b);
	insert(b,a);
	for (int i = 0; i < 7; i++) {
		printf("%d ", a[i]);
	}
	*/


	return 0;
}


float max3(float a, float b, float c)
{
	if (a>b&&a>c) {
		return a;
	}
	else if (b>a&&b>c) {
		return b;
	}
	else {
		return c;
	}
}

int gcd(int a, int b) {
	int rtn_value = -1;
	for (int i = a; i ; i--) {
		if (a%i==0) {
			if (b%i==0) {
				rtn_value = i;
				break;
			}
		}
	}
	return rtn_value;
}

int isPrime(int a) {//a �� ���ԵǸ� �ȵ�.
	int rtn_value=0;
	for (int i = a - 1;i;i--) {
		int sum = 0;
		for (int t = 2; t<=i;t++) {
			if (i%t==0) {
				sum += t;
			}
		}
		if (sum==i) {
			rtn_value = i;
			return rtn_value;
		}
	}
	return rtn_value;
}

//�Ҽ� ������ a�� ���� ã��--�̼�

void insert(int n,int *a) {//int a[7] = { 3,14,15,18,22,35(5) };
	int temp,idx,temp2;
#ifdef debug
	printf("success\n");
#endif
	for (int i = 0; i < 7; i++) {
		if (a[i] < n && n<a[i+1]) {
			temp = a[i + 1];
			a[i + 1] = n;
			idx = i+2;
			break;
		}
		else if (n<a[i]) {
#ifdef debug
			printf("success\n");
#endif
			temp = a[i];
			a[i] = n;
			idx = i+1;
			break;
		}
		else if (a[5]<n) {
			a[6] = n;
			idx = 7;
			break;
		}
	}
	for (int t=idx;t<7;t++) {
		temp2 = a[t];
		a[t] = temp;
		temp = temp2;
	}
}

void sorting(int a[]) {//���� �Է� ������� �����ϴµ�. ���� ��Ʈ Ȱ���غ���.
	//���� ����
	int len=0;
	for (int i=0;i+1;i++)
	{
		if (a[i]!=0)
		{
			len++;
		}
		else
		{
			break;
		}
	}
	for (int i = len-1;i;i--)//9~1 9�� ����
	{
		for (int t=0;t<=i-1;t++)//0~8
		{
			if (a[t]>a[t+1])//�տ��� �ڿ����� ũ�ٸ�--> ����
			{
				int temp=a[t];
				a[t]=a[t+1];
				a[t+1]=temp;
			}
		}
	}
}
/*
#ifdef debug
printf("success\n");
#endif
*/