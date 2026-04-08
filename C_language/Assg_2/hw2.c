#include <stdio.h>

int main(){
	int age;
	double weight;
	char sex;
	int temperature;

	char day;
	char weather;
	//////////////////input
	printf("age, weight, sex, temperature: ");
	scanf("%d %lf %c %d", &age, &weight, &sex, &temperature);
	getchar();//엔터 버퍼 제거
	printf("day (M/T/W/t/F/S/s) : ");
	day=getchar();/////로직 검토 필요 부분
	getchar();//바로 윗줄의 엔터 버퍼 제거
	printf("weather (S/C/R) : ");
	weather = getchar();
	getchar();//바로 윗줄의 엔터 버퍼 제거
	//////////////////output
	putchar('\n');//줄바꿈
	printf("[Age:%16d//%#16o//%#16x]\n", age,age,age);//16.3o 에서 .3을 빼야 할 수도 있음. -> #o, #x 를 통해 해결
	printf("[Weight:%18.3lf]",weight);
	printf("[Sex:%10c]\n",sex);
	printf("[Temperature:%+015d]", temperature);
	printf("[Day:%c]\n", day);
	printf("[Weather:%c]",weather);


	return 0;
}