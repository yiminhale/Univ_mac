#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count=0;
int main(){
	printf("Random number in [10,100]: ");
	srand(time(NULL));
	int num = rand()%91 +10;//0~90까지 좁힌 후 10더해서 10~100까지 랜덤수 만들기.
	printf("%d\n", num);

	printf("Prime numbers [10,%d] : ",num);
	for (int i=10;i<=num;i++)
	{
		int pn=0;
		for (int alpha=2;alpha<i;alpha++)
		{
			if (i%alpha==0)
			{
				pn++;//약수가 등장하면 수 증가
			}
		}
		if (pn==0)//pn 이 0이 이라면==소수라면
		{
			printf("%d ",i);
			count++;
		}
	}
	printf("\nTotal : %d",count);
	return 0;
}
