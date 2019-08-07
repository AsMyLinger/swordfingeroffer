/*
��Ŀ���ؽ�������
���ߣ�������
ʱ�䣺2019-07-28 13:28
�ļ�����interviewQuestion_7.cpp
*/

#include<iostream>

using namespace std;

/*
����������ĳ��������ǰ���������������Ľ�������ؽ����ö����������������ǰ���������������Ľ���ж������ظ������֡�
	  ��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�
ʱ�䣺2019-07-28 13:30
��������printListFromTailToHead
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
	int rootvalue = prestart[0];  //���ڵ�

	BinaryTreeNode* root = Buynode();  //���ڵ㸳��ֵ
	root->m_nValue = rootvalue;
	root->m_pLeft = root->m_pRight = NULL;

	if (prestart == preend)
	{
	
		if (instart == inend && *prestart == *instart)   //�ݹ��˳�������  ָ��ָ���ֵҲ��ͬ
		{
			return root;
		}
		else
		{
			throw exception("��Ч������");  //����������������
		}
	}

	int *rootInorder = instart;            //rootInorderָ����������������ʼλ��
	while (rootInorder <= inend && *rootInorder != rootvalue)   //������������в��ҵݹ�ĸ��ڵ�
	{
		++rootInorder;
	}

	if (rootInorder == inend && *rootInorder != rootvalue)
	{
		throw exception("��Ч������");
	}

	int leftLength = rootInorder - instart;
	int *leftPreorderEnd = prestart + leftLength;  //ǰ������������Ľ�β

	if (leftLength > 0)
	{
		//����������
		root->m_pLeft = constructCore(prestart + 1, leftPreorderEnd, instart, rootInorder - 1);
	}
	if (leftLength < preend - prestart)
	{
		//����������
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