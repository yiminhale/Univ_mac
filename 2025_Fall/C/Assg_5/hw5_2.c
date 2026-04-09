#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("A positive integer (>0): ");
	int input_int=0;
	scanf("%d",&input_int);
	int width=2*input_int+1;
	if (input_int<=0)
	{
		printf("%d is not a positive integer!\n",input_int);
		return 0;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	else if (input_int%2==0)//짝수일 경우 2n+1회 출력해야 함. 다이아몬드 모양
	{
		for (int i = 1;i<=2*input_int+1;i++)//2n+1 반복
		{
			if (i<=input_int+1)
			{
				for (int t=0;t<(width+1-2*i)/2;t++)
				{
					printf(" ");
				}
				for (int t=0;t<2*i-1;t++)
				{
					printf("*");
				}
			}
			else//거울
			{
				int a=2*input_int+2 - i;
				for (int t=0;t<(width+1-2*a)/2;t++)
				{
					printf(" ");
				}
				for (int t=0;t<2*a-1;t++)
				{
					printf("*");
				}
			}
			putchar('\n');
		}
		return 0;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	else if (input_int%2==1)//홀수일 경우 2n+1회 출력해야 함. 나비 모양
	{
		//개별적으로 접근
		for (int i = 1 ;i<=width;i++)
		{
			if (i<input_int+1)
			{
				for (int t=1;t<=i;t++)//i번 반복
				{
					printf("*");
				}
				for (int t = 1;t<=width-2*i;t++)
				{
					printf(" ");
				}
				for (int t=1;t<=i;t++)
				{
					printf("*");
				}
			}
			else if (i==input_int+1)
			{
				for (int t=1;t<=width;t++)
				{
					printf("*");
				}
			}
			else
			{
				int a=2*input_int+2 - i;
				for (int t=1;t<=a;t++)
				{
					printf("*");
				}
				for (int t=1;t<=width-2*a;t++)
				{
					printf(" ");
				}
				for (int t=1;t<=a;t++)
				{
					printf("*");
				}
			}
			putchar('\n');
		}
		return 0;
	}
}