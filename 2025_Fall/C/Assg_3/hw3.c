/*
Req:
[] Enum, switch 사용--
[] 입력 오류 체크--
[] 윤년 확인할 것--
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
 int year, month, day;
 printf("Today [example: 2024 6 12]: ");
 scanf(" %d %d %d", &year, &month, &day);
 printf("%d/%d/%d: ",year,month,day);
 //입력 오류 체크
 if (year<=0||month<=0||month>=13)//년월 입력범위
 {
  printf("Wrong Date!");
  return 0;
 }
 else if (month==1||month==3||month==5||month==7||month==8||month==10||month==12)//일반 날짜 입력범위
 {
  if (day<1||day>=32)
  {
   printf("Wrong Date!");
   return 0;
  }
 }
 else if (month==4||month==6||month==9||month==11)//일반 날짜 입력 범위
 {
  if (day<1||day>=31)
  {
   printf("Wrong Date!");
   return 0;
  }
 }
 else if (month==2)//윤년 날짜 확인(2월만)
 {
  if (year%400==0)//윤년->29일까지
  {
    if (day<1||day>=30)
    {
     printf("Wrong Date!");
     return 0;
    }
  }
  else if (year%100==0)//윤년 아님
  {
   if (day<1||day>=29)
   {
    printf("Wrong Date!");
    return 0;
   }
  }
  else if (year%4==0)//윤년
  {
   if (day<1||day>=30)
   {
    printf("Wrong Date!");
    return 0;
   }
  }
  else
  {
   if (day<1||day>=29)//윤년 아님
   {
    printf("Wrong Date!");
    return 0;
   }
  }
 }


 //계절 판별
 enum season{Spring,Summer,Fall,Winter};
 enum season x;//변수 선언
 if (month==3||month==4||month==5)
 {
  x = Spring;
 }
 else if (month==6||month==7||month==8)
 {
  x=Summer;
 }
 else if (month==9||month==10||month==11)
 {
  x=Fall;
 }
 else
 {
  x=Winter;
 }
switch (x)
{
 case Spring:printf("Spring!\n");
 break;
 case Summer:printf("Summer!\n");
 break;
 case Fall:printf("Fall!\n");
 break;
 case Winter:printf("Winter!\n");
}
return 0;
}
