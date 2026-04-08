#include "Binary_Tree.h"
#include "Tree_Queue.h"

static inline void breath_first_traversal(TreeNode *pRoot);
static inline void postorder(TreeNode *pTree);
static inline void inorder(TreeNode *pTree);
static inline void preorder(TreeNode *pTree);

int main()
{
	printf("Input a string : ");//출력
	//입력
	char input[128];
	scanf("%s",input);
	//tree 구성
	TreeNode *pRoot=CreateRoot();//빈 루트 트리 생성 후 루트 주소 pTree에 저장
	MakeTree(pRoot,input);
	//preorder로 출력
	printf("Pre-order : ");
	TreeNode *ppre=pRoot;
	preorder(ppre);
	putchar('\n');
	//inorder로 출력
	printf("In-order : ");
	TreeNode *pin=pRoot;
	inorder(pin);
	putchar('\n');
	//postorder로 출력
	printf("Post-order : ");
	TreeNode *ppost=pRoot;
	postorder(ppost);
	putchar('\n');
	//breath first로 출력
	printf("Breath First : ");
	TreeNode *pbreath=pRoot;
	breath_first_traversal(pbreath);
	//트리 없애야 함.
	DestroyTree(pRoot);
	//종료
	return 0;
}

static inline void preorder(TreeNode *pTree)
{
	printf("%c",pTree->data);//root 출력
	if (pTree->left!=NULL)//왼쪽이 비어있지 않다면
	{
		preorder(pTree->left);
	}
	if (pTree->right!=NULL)//오른쪽이 비어있지 않다면
	{
		preorder(pTree->right);
	}
}

static inline void inorder(TreeNode *pTree)
{
	if (pTree->left!=NULL)//왼쪽이 비어있지 않다면
	{
		inorder(pTree->left);
	}
	printf("%c",pTree->data);
	if (pTree->right!=NULL)//오른쪽이 비어있지 않다면
	{
		inorder(pTree->right);
	}
}

static inline void postorder(TreeNode *pTree)
{
	if (pTree->left!=NULL)//왼쪽이 비어있지 않다면
	{
		postorder(pTree->left);
	}
	if (pTree->right!=NULL)//왼쪽이 비어있지 않다면
	{
		postorder(pTree->right);
	}
	printf("%c",pTree->data);
}

static inline void breath_first_traversal(TreeNode *pRoot)
{
	Queue *pqueue = CreateQueue(pRoot);//pRoot에 해당하는 데이터가 하나 큐에 삽입된 큐 주소 반환
	while (1)
	{
		TreeNode *pcur=Dequeue(pqueue);
		if (pcur==NULL)
		{
			break;
		}
		printf("%c",pcur->data);
		if (pcur->left!=NULL)
		{
			Enqueue(pqueue,pcur->left);
		}
		if (pcur->right!=NULL)
		{
			Enqueue(pqueue,pcur->right);
		}
	}
	free(pqueue);
}