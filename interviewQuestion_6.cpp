/*
题目：从尾到头打印链表
作者：郭鹏科
时间：2019-07-27 17:18
文件名：interviewQuestion_6.cpp
*/

#include<iostream>
#include<stack>
#include<forward_list>
#include <iterator>
using namespace std;

/*
描述：输入一个链表的头结点，从尾到头反过来打印出每个节点的值
时间：2019-07-27 13:37
函数名：printListFromTailToHead
*/

void printListFromTailToHead(forward_list<int> &pHead)
{
	stack<int> nodes;

	forward_list<int>::iterator it1 = pHead.begin();

	while (it1 != pHead.end())
	{
		nodes.push(*it1);
		it1++;;
	}
	
	while (!nodes.empty())
	{
		cout <<nodes.top()<<" ";
		nodes.pop();
	}
	cout <<endl;
}

/*
//递归打印
void printListFromTailToHead(ListNode* pHead)
{
	if(pHead != NULL)
	{
		if(pHead->m_pNext != NULL)
		{
			printListFromTailToHead(pHead->m_pNext);
		}
		printf("%d\n", pHead->m_nValue);
	}
}
*/

//int main()
//{
//	forward_list<int> list1 = { 1, 2, 3, 4, 5, 6 };
//
//	forward_list<int>::iterator it = list1.begin();
//
//	for (; it != list1.end(); it++)
//	{
//		cout << *it<<" ";
//	}
//	cout << endl;
//
//	printListFromTailToHead(list1);
//
//	return 0;
//}
