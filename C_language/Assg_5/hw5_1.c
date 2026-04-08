#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int input_jinbeob = 0;
	printf("진법 (2~9) : ");
	scanf("%d",&input_jinbeob);

	printf("a positive number of base %d: ",input_jinbeob);
	int input_ori = 0;
	scanf("%d",&input_ori);

	int temp=input_ori;
	int temp_next;
	int count=0;
	while (1)//error check
	{
		temp_next = temp/ 10;
		int d = temp-temp_next*10;
		if (d>=input_jinbeob)
		{
			printf("%d is not a positive number of base %d!\n",d,input_jinbeob);
			return 0;
		}
		temp=temp_next;
		count++;
		if (temp==0)
			break;
	}

	int sum=0;
	for (int i =0;i<=count;i++)//0 1 2 3 순서로 올라가야 함.
	{
		temp_next=input_ori/10;
		int d = input_ori-temp_next*10;
		sum+=d*(int)pow(input_jinbeob,i);
		input_ori=temp_next;
	}
	printf("The decimal number is %d\n",sum);
	return 0;
}