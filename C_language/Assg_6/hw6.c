#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ConvertNum(int num, int base);

int main(){
	printf("A positive integer (>0): ");
	int input_num =0;
	scanf("%d",&input_num);
	if (input_num<=0)
	{
		printf("%d is not a positive integer!\n",input_num);
		return 0;
	}
	printf("Base (2~19) : ");
	int base = 0;
	scanf("%d",&base);
	if (base<2 ||base>19)
	{
		printf("%d is not in between 2 and 19!\n",base);
		return 0;
	}
	printf("The number of %d in %d number system: ",input_num,base);
	ConvertNum(input_num, base);
	putchar('\n');
	return 0;
}

void ConvertNum(int num, int base)
{
	int Q=num,R=0;
	if (Q==0)
	{
		return ;
	}
	R=Q%base;
	Q=Q/base;
	ConvertNum(Q,base);
	if (R<10)
	{
		printf("%d",R);
	}
	else
	{
		switch (R)
		{
		case 10:printf("A");break;
		case 11:printf("B");break;
		case 12:printf("C");break;
		case 13:printf("D");break;
		case 14:printf("E");break;
		case 15:printf("F");break;
		case 16:printf("G");break;
		case 17:printf("H");break;
		case 18:printf("I");break;
		}
	}
}