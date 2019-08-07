/*
��Ŀ������������һ�����
���ߣ�������
ʱ�䣺2019-07-28 16:06
�ļ�����interviewQuestion_8.cpp
*/

#include<iostream>
using namespace std;

/*
����������һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�
	 ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣
ʱ�䣺2019-07-28 16:07
��������getNext
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
	if (pNode->m_pRight != NULL)           //��1��
	{
		BinaryTreeNode* pRight = pNext->m_pRight;
		while (pRight->m_pLeft != NULL)
		{
			pRight = pRight->m_pLeft;
		}
		pNext = pRight;
	}
	else if (pNode->m_pParent != NULL)      //��2��
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
