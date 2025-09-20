#include <stdio.h>

int main()
{
	int a,b;
	int *p;
	int *q;

	a=10;
	b=5;

	p = &a;
	q = &b;
	printf("%p\n",p);
	printf("%p\n",q);
	*p = *q;
	p=q;
	printf("%p\n",p);
	printf("%p\n",q);
	printf("%d\n",a);
	printf("%d\n",b);
	printf("%d\n",*p);
	printf("%d\n",*q);
	return 0;
}