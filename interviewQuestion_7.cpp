/*
题目：重建二叉树
作者：郭鹏科
时间：2019-07-28 13:28
文件名：interviewQuestion_7.cpp
*/

#include<iostream>

using namespace std;

/*
描述：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
	  例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
时间：2019-07-28 13:30
函数名：printListFromTailToHead
*/

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode * Buynode()
{
	BinaryTreeNode *s = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	if (NULL == s) exit(1);
	memset(s, 0, sizeof(BinaryTreeNode)); // new;
	return s;
}

void InOrder(BinaryTreeNode *p)
{
	if (NULL != p)
	{
		InOrder(p->m_pLeft);
		cout << p->m_nValue <<" ";
		InOrder(p->m_pRight);
	}
}

BinaryTreeNode* constructCore(int *prestart, int *preend, int *instart, int *inend)
{
	int rootvalue = prestart[0];  //根节点

	BinaryTreeNode* root = Buynode();  //根节点赋初值
	root->m_nValue = rootvalue;
	root->m_pLeft = root->m_pRight = NULL;

	if (prestart == preend)
	{
	
		if (instart == inend && *prestart == *instart)   //递归退出的条件  指针指向的值也相同
		{
			return root;
		}
		else
		{
			throw exception("无效的输入");  //遍历数组输入有误
		}
	}

	int *rootInorder = instart;            //rootInorder指向中序遍历数组的起始位置
	while (rootInorder <= inend && *rootInorder != rootvalue)   //中序遍历数组中查找递归的根节点
	{
		++rootInorder;
	}

	if (rootInorder == inend && *rootInorder != rootvalue)
	{
		throw exception("无效的输入");
	}

	int leftLength = rootInorder - instart;
	int *leftPreorderEnd = prestart + leftLength;  //前序遍历左子树的结尾

	if (leftLength > 0)
	{
		//构建左子树
		root->m_pLeft = constructCore(prestart + 1, leftPreorderEnd, instart, rootInorder - 1);
	}
	if (leftLength < preend - prestart)
	{
		//构建右子树
		root->m_pRight = constructCore(leftPreorderEnd + 1, preend, rootInorder + 1, inend);
	}

	return root;
}

BinaryTreeNode* reConstructBinaryTree(int pre[], int in[], int length)
{
	if (NULL == *pre || NULL == in || length <= 0)
	{
		return NULL;
	}

	return constructCore(pre, pre + length - 1, in, in + length - 1);
}

//int main()
//{
//	int preorder[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
//	int infixorder[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
//
//	int length = sizeof(preorder) / sizeof(preorder[0]);
//
//
//	BinaryTreeNode* root = reConstructBinaryTree(preorder, infixorder, length);
//
//	InOrder(root);
//	cout << endl;
//
//	return 0;
//}