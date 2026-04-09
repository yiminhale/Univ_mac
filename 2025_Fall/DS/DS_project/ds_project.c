#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "Link.h"

int cycle(Stack *pStack,Queue *pQueue);

int main(void) {
	Stack* pStack = CreateStack(1024);
	Queue* pQueue = Q_Create(1024);
	cycle(pStack, pQueue);
	return 0;
}

int cycle(Stack* pStack, Queue* pQueue) {
	printf("ARRIVE <ID>, REPORT, SERVE, WASH <INT>, Quit : ");
	char input[32];
	scanf(" %[^\n]", input);
	if (input[0] == 'Q'||input[0]=='q') {//quit
		printf("Quit!\n");
		DestroyStack(pStack);
		Q_Destroy(pQueue);
		return 0;
	}
	
	else if (input[0]=='A'||input[0]=='a') {//arrive
		char* temp=NULL;
		char* decimal_start = strpbrk(input/*�ᱹ �ּ� ���۰��� �ǹ�*/, "0123456789");//�ּҺ��� �ǹ��ϴ� ��: "123 456 789..."
		
		char* decimal_end = strpbrk(decimal_start, " \0");//�ּҺ��� �ǹ��ϴ� ��: "\\456\\789..."
		temp = decimal_end;
		
		*decimal_end = '\0';
		
		int id = atoi(decimal_start);
		Q_Enqueue(pQueue, id);
		printf("%d enqueue\n", id);
		
		putchar('\n');
		cycle(pStack, pQueue);//�ݺ�
	}
	else if ((input[0]=='R'||input[0]=='r') && input[1] == 'e') {//report
		printf("Q=<");
		//queue ��ȸ
		QNode* pcur = pQueue->pfront;
		if (Q_isEmpty(pQueue)) {
			printf("-");
		}
		else {
			while (pcur != pQueue->prear) {
				printf(" %d,", pcur->data);
				pcur = pcur->next;
			}
			printf(" %d", pcur->data);
		}
		printf(">; PLATES=<");
		//���� ��ȸ
		SNode* pscur = pStack->top;
		if (IsEmptyStack(pStack)) {
			printf("-");
		}
		else {
			while (pscur != NULL) {
				printf(" %d", pscur->data);
				pscur = pscur->next;
				if (pscur != NULL) {
					printf(",");
				}
			}
		}
		printf(">\n");
		cycle(pStack, pQueue);//�ݺ�
	}
	else if (input[0]=='S') {//serve
		if (IsEmptyStack(pStack)||Q_isEmpty(pQueue)) {
			printf("WAIT\n");
			printf(">\n");
			cycle(pStack, pQueue);//�ݺ�
		}
		else {
			printf("SERVE %d %d\n", Q_Dequeue(pQueue),Pop(pStack));
			printf(">\n");
			cycle(pStack, pQueue);//�ݺ�
		}
	}
	else if (input[0]=='W') {//wash
		input[strlen(input) + 1] = '\0';
		char* temp1 = input;
		int plate;
		char* decimal_start;
		char* decimal_end;
		do {
			
			decimal_start = strpbrk(temp1/*�ᱹ �ּ� ���۰��� �ǹ�*/, "0123456789");//�ּҺ��� �ǹ��ϴ� ��: "123 456 789..."
			/*printf("decimal_start = %p \n", decimal_start);*/
			
			decimal_end = strpbrk(decimal_start, " \0");//�ּҺ��� �ǹ��ϴ� ��: "\\456\\789..."
			
			temp1 = decimal_end;
			/*printf("decimal_end = %p \n", decimal_end);*/
			if (temp1[1] == '\0' && temp1[0] == '\0') {
				printf("succ\n");
				plate = atoi(decimal_start);
				Push(pStack, plate);
				printf("%d push\n", plate);
				break;
			}
			else { 
				*decimal_end = '\0';
			}////////�̰� ����
			/*printf("success!\n");*/
			plate = atoi(decimal_start);
			Push(pStack, plate); 
			printf("%d push\n", plate);
		} while (temp1[2] != '\0');
		putchar('\n');
		cycle(pStack, pQueue);//�ݺ�
	}
}