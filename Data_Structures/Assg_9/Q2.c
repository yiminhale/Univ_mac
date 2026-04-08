#include "Sorting.h"

int main()
{
    printf("Input file name : ");
    char filename[256]={0};
    scanf("%s",filename);
    //파일 읽고 배열에 배속시키기
    FILE *fp=fopen(filename,"r");
    if (fp==NULL)
    {
        printf("wrong input file!\n");
        return 0;
    }//파일 입력 체크

    int obj[1024]={0};//배속시킬 총 배열
    char temp[128]={0};//각 라인에 사용할 임시 배열( 문자열을 읽어와야 하기에 )
    int idx=0;//인덱스용
    while (fgets(temp,sizeof(temp),fp)!=NULL)//10줄이고 각 줄에 여러개 있다고 하자.
    {
        char* ptr = temp;//배열 시작 받음
        //일단 strtok으로 공백을 기준으로 끊음
        ptr=strtok(ptr," \t\n");//ptr 위치부터 시작해서 해당 문자 만나면 \0으로 끊는게 맞나? ㅇㅇ
        while (ptr != NULL)//끝나지 않았다면 반복
        {
            //해당 숫자(현재는 문자)를 정수로 전환
            //obj에 저장 및 idx 증가
            obj[idx++]=(int)strtol(ptr,NULL,10);
            //다음 위치로 이동
            ptr=strtok(NULL," \t\n");
        }
    }
    /*
    int temp=0;
    int idx=0;
    while(fscanf(fp,"%d",&temp)==1){
        object[idx++]=temp;
    }
     */
    fclose(fp);

    //정렬 방법 입력받기
    printf("Choose a sorting method to use (Selection: 0, Insertion: 1, Bubble: 2, Quick: 3, Merge: 4) : ");
    char method[16]={0};
    fgets(method,sizeof(method),stdin);
    long int_method = strtol(method,NULL,10);
    //정렬하기. 함수 사용
    switch (int_method)
    {
    case 0: selection_sort(obj,idx);break;
    case 1: insertion_sort(obj,idx);break;
    case 2: bubble_sort(obj,idx);break;
    case 3: quick_sort(obj,idx);break;
    case 4: merge_sort(obj,idx);break;
    default: printf("NULL\n");return 0;
    }
    //출력하기
    print_array(obj,idx);
    //종료
    return 0;
}
