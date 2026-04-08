#ifndef ASSG_9_SEARCH_H
#define ASSG_9_SEARCH_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;

static inline bool binarySearch(void** arr,int tg);
static inline bool hashSearch(void** arr,int tg);

static inline bool binarySearch(void** arr,int tg)//얘는 정렬되어 있어야 함. 즉, 정렬부터 하기.
{
    bool rtn=-1;

    //종료
    return rtn;
}

static inline bool hashSearch(void** arr,int tg)//방법: 모듈로. 사이즈는 1024이므로 %1024
{                                               //충돌 해결:
    bool rtn=-1;//있으면 1, 없으면 0

    //종료
    return rtn;
}

#endif //ASSG_9_SEARCH_H