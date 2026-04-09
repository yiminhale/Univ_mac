/*
 자료구조 퀴즈
main 을 변형하지 말고, 결과가 다음처럼 나와야 함.
./main
# of input pairs : 3
in1 in2 : 2 45
in1 in2 : 3 4
in1 in2 : 54 23
2 + 45 = 47
3 + 4 = 7
54 + 23 = 77
*/
////////////////////////
#include <stdio.h>
#include <stdlib.h>
////////////////////////
void get_in(int **a, int **b, int c);
int *add(int *x, int *y, int z);//주소를 반환해서 result에 저장. A[i]==*(A+i) 활용
int *result=NULL;
/////////////////////////main()은 변형 금지
int main(void)
{
 int count, i;//count는 총 몇개의 쌍인지, i 는 for 문에서 활용
 int *in1=NULL, *in2=NULL, *in3=NULL;

 printf("#of input pairs: ");//몇 개의 쌍을 입력받을 것인지 물어보는 파트
 scanf("%d",&count);// 총 몇 개의 쌍을 입력받을지에 대한 변수 입력
///////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
 get_in(&in1, &in2, count);//함수 설계해야 함.--완료
 result=add(in1,in2,count);//함수 설계해야 함. 현재 in1, in2에는 메모리할당받은 주소가 적혀있음.
 ///////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////
 for (i=0;i<count;i++)//결과물 출력 파트
  printf("%d + %d = %d\n",in1[i],in2[i],result[i] );//이것으로 말미암아, get_in과 result는 배열 혹은 메모리 주소에 차례대로 저장해야 함.

 free(in1);//메모리 해제: 메모리에 할당해줘야 한다는 의미.--완료
 free(in2);//메모리 해제: 메모리에 할당해줘야 한다는 의미.--완료
 free(result);//메모리 해제: loc_result의 주소를 그대로 받아와서 사용

 return 0;
}
/////////////////////////

//////////////////////함수 작성 파트
void get_in(int **a, int **b, int c)//c에 count 들어옴.
{
 *a = calloc(c, sizeof(int));//&in1 의 주소에 해당하는 변수 in1에 calloc으로 할당한 메모리 첫주소 저장.
 *b = calloc(c, sizeof(int));//&in2 의 주소에 해당하는 변수 in1에 calloc으로 할당한 메모리 첫주소 저장.
 for (int loc_count=0;c>0;c--,loc_count++)//c 만큼 반복
 {
  printf("in1 in2 : ");
  scanf(" %d %d",*a+loc_count,*b+loc_count);
 }
}
//////////////////////
int *add(int *x, int *y, int z)//z에 count 들어옴. x에는 in1, y에는 in2가 들어옴. 각각 메모리 할당받은 주소 가리킴.
{
 int *loc_result = calloc(z,sizeof(int));
 for (int loc_count=0;z;loc_count++,z--)//c)//in1과 in2에 해당하는 변수들 더해서 반환해야 함.
 {
  *(loc_result+loc_count)=*(x+loc_count)+*(y+loc_count);
 }
 return loc_result;
}