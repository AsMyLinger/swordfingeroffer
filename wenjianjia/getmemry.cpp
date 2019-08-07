#include<windows.h>
#include<assert.h>
#include<limits.h>
#include<iostream>
#include<vector>
#include<time.h>
#include<stack>
#include<queue>
#include<ctype.h>
using namespace std;

typedef char  ElemType; //int
#define END  '#'        //-1
typedef struct BtNode
{
	BtNode *leftchild;
	BtNode *rightchild;
	ElemType data;
}BtNode,*BinaryTree;

BtNode * Buynode()
{
	BtNode *s = (BtNode*)malloc(sizeof(BtNode));
	if(NULL == s) exit(1);
	memset(s,0,sizeof(BtNode)); // new;
	return s;
}

void Freenode(BtNode *p)
{
	free(p);
}

//字符串形式创建二叉树
BtNode * CreateTree(ElemType* &str)
{
	BtNode *s = NULL;
	if(NULL != str && *str != END)
	{
		s = Buynode();
		s->data = *str;
		s->leftchild = CreateTree(++str);
		s->rightchild = CreateTree(++str);
	}
	return s;
}

void InOrder(BtNode *p)
{
	if (NULL != p)
	{
		InOrder(p->leftchild);
		cout << p->data << " ";
		InOrder(p->rightchild);
	}
}

int main()
{
	char* str = "ABC##DE##F##G#H##";
	BinaryTree root = CreateTree(str);
	InOrder(root);
	return 0;
}
