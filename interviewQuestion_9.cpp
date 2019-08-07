/*
题目：用两个栈实现队列、用两个队列实现栈
作者：郭鹏科：
时间：2019-07-31 18:17
文件名：interviewQuestion_9.cpp
*/

#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;

/*
描述：用两个栈实现队列。队列的声明如下，请实现它的两个函数appendTail和deletedHead,分别完成在队列尾部插入节点和在队列头部删除节点的功能。
时间：2019-07-31 20:27
类名：CQueue
*/

template <class T>
class CQueue
{
public:
	//CQueue();
	//~CQueue();
	void appendTail(const T& node);
	T deleteHead();
private:
	stack<T> stack1;
	stack<T> stack2;
};

template <class T>
void CQueue<T>::appendTail(const T& node)   //入队列，只从stack1入
{
	stack1.push(node);
}

template <class T>
T CQueue<T>::deleteHead()                  //当stack2不为空时，从stack1出，如果为空，则将stack1中的元素出战，压入stack2。
{
	if (stack2.size() <= 0)
	{
		if (stack1.size() <= 0)
			throw exception("the queue is empty");//两个栈都为空
		else
		{//stack1不为空，stack2为空，则stack1全部入stack2
			while (stack1.size() > 0)
			{
			    T value = stack1.top();
				stack2.push(value);
			    stack1.pop();
			}
		}
	}//stack2不为空则直接输出
	T r_value = stack2.top();
	stack2.pop();
	return r_value;
}


/*
描述：用两个栈实现一个队列。用两个队列实现栈，栈的声明如下，分别实现栈的push()函数和topAnddelete()函数，
用来完成在栈的顶部插入和删除（返回栈顶值）的操作
时间：2019-07-31 20:27
类名：CStack
*/

template <class T>
class CStack
{
public:
	//CStack();
	//~CStack();
	void appendTail(const T& node);
	T topAnddelete();
private:
	queue<T> queue1;
	queue<T> queue2;
};

template <class T>
void CStack<T>::appendTail(const T& node)  //可以选择任意一个队列进行入栈操作
{
	queue1.push(node);
}

template <class T>
T CStack<T>::topAnddelete()
{
	if (queue1.empty() && queue2.empty())
	{//若为空抛出异常
		throw exception("the stack is empty");	
	}
	else if (!queue1.empty() && queue2.empty())
	{//queue1不为空，queue2为空
		while (queue1.size() > 1)
		{
			 T value = queue1.front();
			 queue2.push(value);
			 queue1.pop();
		}
		T r_value = queue1.front();  //此时队列只剩刚进来的元素
		queue1.pop();
		return r_value;
	}
	else
	{//queue2不为空，queue1为空
		while (queue2.size() > 1)
		{
			T value = queue2.front();
			queue1.push(value);
			queue2.pop();
		}
		T r_value = queue2.front();
		queue2.pop();
		return r_value;
	}
}

//int main()
//{
//	/*CQueue<string> queue;
//	queue.appendTail("a");
//	queue.appendTail("b");
//	queue.appendTail("c");
//
//	cout <<queue.deleteHead() << endl;
//	cout << queue.deleteHead() << endl;
//	cout << queue.deleteHead() << endl;*/
//
//	CStack<string> st;
//	st.appendTail("a");
//	st.appendTail("b");
//	st.appendTail("c");
//
//	cout << st.topAnddelete() << endl;
//	cout << st.topAnddelete() << endl;
//	cout << st.topAnddelete() << endl;
//
//	return 0;
//}