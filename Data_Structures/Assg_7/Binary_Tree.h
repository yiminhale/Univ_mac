#ifndef ASSG_7_BINARY_TREE_H
#define ASSG_7_BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef char Element;//문자 하나를 각 노드의 원소로 지정

typedef struct TreeNode
{
	Element data;
	struct TreeNode *left,*right;
}TreeNode;

static inline TreeNode *CreateRoot()
{
	TreeNode *pRoot = (TreeNode*)calloc(1,sizeof(TreeNode));
	if (pRoot==NULL)
	{
		return NULL;
	}
	pRoot->data='\0';
	/*
	pRoot->left=(TreeNode*)calloc(1,sizeof(TreeNode));//널로 해야 하나?
	pRoot->right=(TreeNode*)calloc(1,sizeof(TreeNode));//널로 해야 하나?
	*/
	pRoot->left=NULL;
	pRoot->right=NULL;//문제시 위 방법으로 회귀
	return pRoot;
}

static inline void MakeTree(TreeNode *pRoot,char input[128])//최상위루트와 입력 문자열 받음//예시: abcdefg
{
	int count = (int) strlen(input);//총 input이 몇개인지//예: 7
	/*
	insert(root,input[0]);//일단 루트에 첫번째 원소 삽입
	*/
	pRoot->data=input[0];
	for (int i =1;i<count;i++)//문자열 길이만큼 반복한다.//예: 1~6까지 6번 반복
	{
		//루트에서 왼쪽 오른쪽 갈림길 이정표 완성하기
		int temp=i+1;//입력의 몇 번째 문자열을 대상으로 할 것인지
		char save[128]="";//l, r 저장용
		while (temp!=1)//1이 되면 스탑
		{
			if (temp%2==0)//짝수라면
			{
				strcat(save,"l");
			}
			else if (temp%2!=0)//홀수라면
			{
				strcat(save,"r");
			}
			temp = temp/2;//정수연산
		}//이거생각하기 개힘드네 진짜

		//루트에서 해당 위치까지 포인터 타고 내려가기
		int times = (int)strlen(save);//save 길이==몇 번 타고 내려갈건지
		TreeNode *pcur=pRoot;//루트 주소 복사
		for (int a = times;1<a;a--)//a-1 번 타고 내려가라
		{
			if (save[a-1]=='l')//역방향 읽어서 l이라면
			{
				pcur=pcur->left;
			}
			else if (save[a-1]=='r')//역방향 읽어서 r이라면
			{
				pcur=pcur->right;
			}
		}
		if (save[0]=='l')//역방향 읽어서 l이라면
		{
			pcur->left=(TreeNode*)calloc(1,sizeof(TreeNode));
			pcur->left->data=input[i];
			pcur->left->left=pcur->left->right=NULL;
		}
		else if (save[0]=='r')//역방향 읽어서 r이라면
		{
			pcur->right=(TreeNode*)calloc(1,sizeof(TreeNode));
			pcur->right->data=input[i];
			pcur->right->left=pcur->right->right=NULL;
		}
		/*
		pcur->left=(TreeNode*)calloc(1,sizeof(TreeNode));
		pcur->right=(TreeNode*)calloc(1,sizeof(TreeNode));
		*/
	}
}

static inline void DestroyTree(TreeNode *pRoot)
{
	if (pRoot->left!=NULL)
	{
		TreeNode *l=pRoot->left;
		DestroyTree(l);
	}
	if (pRoot->right!=NULL)
	{
		TreeNode *r=pRoot->right;
		DestroyTree(r);
	}
	free(pRoot);
}


#endif //ASSG_7_BINARY_TREE_H
