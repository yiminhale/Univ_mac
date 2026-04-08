#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Stack_Array.h"
#include "Queue_Array.h"

void Stat_Queue(Queue* queue);
void Serve_Stack(char* menu);

Queue* q; Stack* s;
int i, select, valid_num;
char menu[100];
char* temp;

int main(void) {
	q = CreateQueue(100);
	s = CreateStack(100);
	valid_num = 1;
	
	while (1) {
		printf("Order (0), Serve (1), Exit (2) : ");
		scanf("%d", &select);

		switch (select) {
			case 0:
				printf("Order : ");
				scanf(" %[^\n]", menu);

				for (i = 0; i < strlen(menu); i++){
					//숫자 외 입력 필터(문자, space, etc...)
					if (!isdigit(menu[i])) {
						printf("Wrong input! Only digits allowed.(Space also not allowed)\n");
						valid_num = 0;
						break;
					}
					//0 혹은 5 초과 숫자 입력 필터
					if (menu[i] - '0' || menu[i] - '0' > 5) {
						printf("You put invalid food number. Only 5 menu we have.\n");
						valid_num = 0;
						break;
					}
				}

				if (!valid_num)
					break;

				Enqueue(q, menu);

				printf("Stat : ");
				Stat_Queue(q);
				break;

			case 1:
				if (!IsEmptyQueue(q)) {
					printf("Serve : ");

					temp = Dequeue(q);
					Serve_Stack(temp);

					free(temp);
				}
				else
					printf("Queue is empty !\n");

				printf("Stat : ");
				Stat_Queue(q);
				break;

			case 2:
				DestroyQueue(q);
				DestroyStack(s);
				return 0;
		}
		printf("\n");
	}
}

void Stat_Queue(Queue* q) {
	int order;

	if (IsEmptyQueue(q)){
		printf("(0)\n");
		return;
	}

	order = 0;
	i = (q->front + 1) % q->size;

	while (i != (q->rear + 1) % q->size) {
		printf("%s", q->queue[i]);
		order++;
		if ((i + 1) % q->size != (q->rear + 1) % q->size)
			printf(", ");
		i = (i + 1) % q->size;
	}
	printf("(%d)\n", order);
}

void Serve_Stack(char* temp) {
	int food_num;

	for (i = 0; i < strlen(temp); i++){
		Push(s, temp[i] - '0');
	}
	while(!IsEmptyStack(s)){
		food_num = Pop(s);
		switch (food_num){
			case 1:
				printf("Ice cream"); break;
			case 2:
				printf("Bibimbab"); break;
			case 3:
				printf("Bulgogi"); break;
			case 4:
				printf("Coffee"); break;
			case 5:
				printf("Noodle"); break;
		}
		if (!IsEmptyStack(s))
			printf(", ");
	}
	printf("\n");
}