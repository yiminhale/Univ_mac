#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define SIZE 9//10대부터 90대까지 9개
#define NUM 50

typedef struct
{
	int min[SIZE];
	int max[SIZE];
	int count[SIZE];
}Stat;

void StoreRand(char filename[]);
Stat ReadData(char filename[]);
void PrintData(Stat dstat);

int main()
{
	char filename[100];
	Stat data;//구조체 변수 선언

	printf("Filename: ");
	scanf("%s",filename);

	StoreRand(filename);
	data = ReadData(filename);
	PrintData(data);
	return 0;
}

void StoreRand(char filename[])
{
	FILE* fp=fopen(filename,"w");
	srand(time(NULL));//seed random
	for (int t = 1;t<=5;t++)//5번 반복. 줄바꿈용
	{
		for (int i =1;i<=10;i++)//10번 반복. 한 줄에 10개
		{
			int random = (int)rand()%90 + 10;//10~99
			fprintf(fp,"%d ",random);
			printf("%d ",random);
		}
		fprintf(fp,"\n");
		printf("\n");
	}
	fclose(fp);
}

Stat ReadData(char filename[])
{
	FILE* fp = fopen(filename,"r");
	if (!fp)
	{
		printf("sth wrong!\n");
		Stat error={0};
		return error;
	}
	Stat data={0};
	//min위해 초기화 필요
	for (int i = 0;i<SIZE;i++)
	{
		data.min[i]=999;
	}
	int ori;
	while (fscanf(fp,"%d",&ori)==1)
	{
		int idx = ori/10 - 1;//49-->3,44-->3
		data.count[idx]++;
		if (data.max[idx]<ori)
		{
			data.max[idx]=ori;
		}

		if (ori<data.min[idx])
		{
			data.min[idx]=ori;
		}
	}
	fclose(fp);
	return data;
}

void PrintData(Stat dstat)
{
	printf("[Data Statistics]\n\tMin\tMax\tCount\n");
	for (int i = 0;i<SIZE;i++)//9번 반복
	{
		printf("%ds:\t%d\t%d\t%d\n",i*10+10,dstat.min[i],dstat.max[i],dstat.count[i]);
	}
}
