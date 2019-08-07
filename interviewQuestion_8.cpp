/*
题目：二叉树的下一个结点
作者：郭鹏科
时间：2019-07-28 16:06
文件名：interviewQuestion_8.cpp
*/

#include<iostream>
using namespace std;

/*
描述：给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
	 注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
时间：2019-07-28 16:07
函数名：getNext
*/
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode* m_pParent;
};


BinaryTreeNode* getNext(BinaryTreeNode* pNode)
{
	if (NULL == pNode)
	{
		return NULL;
	}

	BinaryTreeNode* pNext = NULL;
	if (pNode->m_pRight != NULL)           //第1点
	{
		BinaryTreeNode* pRight = pNext->m_pRight;
		while (pRight->m_pLeft != NULL)
		{
			pRight = pRight->m_pLeft;
		}
		pNext = pRight;
	}
	else if (pNode->m_pParent != NULL)      //第2点
	{
		BinaryTreeNode* tmp = pNode;
		BinaryTreeNode* pParent = pNode->m_pParent;
		while(pParent!=NULL && tmp==pParent->m_pRight)
		{
			tmp = pParent;
			pParent = pParent->m_pParent;
		}
		pNext = pParent;
	}
	return pNext;
}

//int main()
//{
//
//	return 0;
//}
