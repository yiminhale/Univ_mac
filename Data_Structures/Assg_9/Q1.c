#include "Search.h"

/*
 * 1. binary search
 * 2. hashed search
 * 임의로 입력된 정수에서 특정 정수를 찾는 프로그램.
 */

int main()
{
    //단순 출력 및 파일입력 대기
    printf("Input file name : ");
    char filename[256]={0};
    scanf("%s",filename);
    printf("Target Integer : ");
    int tg=0;
    scanf("%d",&tg);
    //파일 컨트롤
    FILE *fp=fopen(filename,"r");
    if (fp==NULL)
    {
        printf("file input wrong!\n");
        return 0;//종료
    }
    /*
    int arr[1024]={0};
    int idx=0;
    while (fscanf(fp,"%d",&arr[idx])==1)
    {
        ++idx;
    }
    *///솔직히 너무 쉽다. 제네릭으로 해보자.
    void *arr[1024]={0};
    int idx=0;//길이를 의미하기도 함.
    int temp[1024]={0};
    while (fscanf(fp,"%d",&temp[idx])==1)
    {
        arr[idx]=&temp[idx];
        idx++;
    }//근데 이러면 제네릭이 제네릭이 아닌거 아님? 무늬만 제네릭 같은데.
    fclose(fp);
    //서칭하기.
    printf("Choose a searching method (Binary:1, Hashed:2) : ");
    int branch=0;
    scanf("%d",&branch);
    bool rtn;
    switch (branch)
    {
    case 1: rtn=binarySearch(arr,tg);
        if (rtn==0)
        {
            printf("%d is not found!",tg);
            return 0;
        }
        else if (rtn==1)
        {
            printf("%d is found!\n",tg);
            return 0;
        }
        break;
    case 2: rtn=hashSearch(arr,tg);
        if (rtn==0)
        {
            printf("%d is not found!",tg);
            return 0;
        }
        else if (rtn==1)
        {
            printf("%d is found!\n",tg);
            return 0;
        }
        break;
    default: break;
    }
    //종료
    return 0;
}