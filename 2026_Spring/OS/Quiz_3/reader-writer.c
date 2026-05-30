#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "common_threads.h"

//
// Your code goes in the structure and functions below
//

typedef struct __rwlock_t {//과제에서 제공됨.
    sem_t lock;//L 세마포어
    sem_t writelock;//WL 세마포어
    int readers;//R 수 
} rwlock_t;//구조체.


void rwlock_init(rwlock_t *rw) {//구조체 주소 rw를 인자로 받는 함수. lock 초기화
    Sem_init(&rw->lock, 1 );//처음엔 누구나 진입 가능해야 함. 
    Sem_init(&rw->writelock,1);//처음엔 누구나 진입 가능해야 함. 
    rw->readers=0;
}

void rwlock_acquire_readlock(rwlock_t *rw) {//readL 획득 함수: 과제에서 제공됨
    Sem_wait(&rw->lock);//P. cs처리 위해
    rw->readers++;//R 한명 추가
    if(rw->readers == 1){//한명이라도 R 있으면
        Sem_wait(&rw->writelock);//WL 걸어서 W 접근금지
    }
    Sem_post(&rw->lock);//V. cs 끝.
}

void rwlock_release_readlock(rwlock_t *rw) {//readL 해제 함수
    Sem_wait(&rw->lock);//P. cs처리 위해서
    rw->readers--;//다읽었으니 R 한명 사라집니다.
    if(rw->readers==0){//더 읽을 사람 아무도 없으면
        Sem_post(&rw->writelock);//W 써도 돼요
    }
    Sem_post(&rw->lock);//V. cs 끝.
}

void rwlock_acquire_writelock(rwlock_t *rw) {//WL 획득 함수. 과제에서 제공
    Sem_wait(&rw->writelock);//P. WL 걸기. 쓰는건 나만 써야 하니까. 
}

void rwlock_release_writelock(rwlock_t *rw) {//WL 해제 함수
    Sem_post(&rw->writelock);//V. WL 해제. 다썼으니. 
}

//
// Don't change the code below (just use it!)
// 

int loops;//전역변수 선언
int value = 0;//0으로 초기화.

rwlock_t lock;//구조체 선언. 

void *reader(void *arg) {//R 함수. 
    int i;//내부적으로 변수 하나 선언
    for (i = 0; i < loops; i++) {//반복. loops 수치만큼 반복
	rwlock_acquire_readlock(&lock);//readL 휙득
	printf("read %d\n", value);//단순 프린트. 현재 value를 출력.
    sleep(1);//과제에서 배치하는 위치
	rwlock_release_readlock(&lock);//readL 해제.
    }
    return NULL;
}

void *writer(void *arg) {//W 함수. 
    int i;//내부 변수 하나 선언: 반복문 용도
    for (i = 0; i < loops; i++) {//반복. loops 수치만큼 반복
	rwlock_acquire_writelock(&lock);//writeL 휙득
	value++;//value 1증가
	printf("write %d\n", value);//단순 프린트. 현재 value를 출력.
    sleep(1);//과제에서 배치하는 위치
	rwlock_release_writelock(&lock);//writeL 해제.
    }
    return NULL;
}

int main(int argc, char *argv[]) {//파라1: 파라2:배열이름->포인터 주소로 받고, 역참조시 char 타입 배열.
    assert(argc == 4);//파라1이 4라면 pass, 4가 아니라면 강제 종료. 
    int num_readers = atoi(argv[1]);//배열의 2번째 원소-> R 수-> 이 변수에 대입
    int num_writers = atoi(argv[2]);//배열의 3번째 원소-> W 수-> 이 변수에 대입
    loops = atoi(argv[3]);//배열의 4번째 원소-> 전역변수 loops 초기화.

    pthread_t pr[num_readers], pw[num_writers];

    rwlock_init(&lock);//구조체 주소 파라로 넘김. 

    printf("begin\n");//시작한다는 단순 출력

    int i;//반복용 변수
    for (i = 0; i < num_readers; i++)//R 수만큼 반복
	Pthread_create(&pr[i], NULL, reader, NULL);//R 쓰레드 생성: R개 만큼
    for (i = 0; i < num_writers; i++)//W 수만큼 반복
	Pthread_create(&pw[i], NULL, writer, NULL);//W 쓰레드 생성: W개 만큼

    for (i = 0; i < num_readers; i++)//R 수만큼 반복
	Pthread_join(pr[i], NULL);//
    for (i = 0; i < num_writers; i++)//W 수만큼 반복
	Pthread_join(pw[i], NULL);//

    printf("end: value %d\n", value);//끝. value 출력

    return 0;//종료
}

