#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void CountAlphabet(char* in_str)
{
	int result[26]={0};//0: A, 1: B ... 25: Z
	for (int i = 0;i<(int)strlen(in_str);i++)
	{
		int stdd = (int)in_str[i];
		if ('a'<=stdd&&stdd<='z')
		{
			int idx = stdd-'a';//a: 0, b: 1 ... z: 25
			result[idx]++;
		}
		else if ('A'<=stdd&&stdd<='Z')
		{
			int idx = stdd-'A';//a: 0, b: 1 ... z: 25
			result[idx]++;
		}
	}

	for (int i = 0;i<26;i++)
	{
		if (result[i]!=0)
		{
			printf("%c or %c: ----> %d\n",'a'+i,'A'+i,result[i]);
		}
	}
}


int main()
{
	char s[100];
	printf("A String : ");
	scanf("%s",s);

	CountAlphabet(s);
	return 0;
}