/*
��Ŀ��������ջʵ�ֶ��С�����������ʵ��ջ
���ߣ������ƣ�
ʱ�䣺2019-07-31 18:17
�ļ�����interviewQuestion_9.cpp
*/

#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;

/*
������������ջʵ�ֶ��С����е��������£���ʵ��������������appendTail��deletedHead,�ֱ�����ڶ���β������ڵ���ڶ���ͷ��ɾ���ڵ�Ĺ��ܡ�
ʱ�䣺2019-07-31 20:27
������CQueue
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
void CQueue<T>::appendTail(const T& node)   //����У�ֻ��stack1��
{
	stack1.push(node);
}

template <class T>
T CQueue<T>::deleteHead()                  //��stack2��Ϊ��ʱ����stack1�������Ϊ�գ���stack1�е�Ԫ�س�ս��ѹ��stack2��
{
	if (stack2.size() <= 0)
	{
		if (stack1.size() <= 0)
			throw exception("the queue is empty");//����ջ��Ϊ��
		else
		{//stack1��Ϊ�գ�stack2Ϊ�գ���stack1ȫ����stack2
			while (stack1.size() > 0)
			{
			    T value = stack1.top();
				stack2.push(value);
			    stack1.pop();
			}
		}
	}//stack2��Ϊ����ֱ�����
	T r_value = stack2.top();
	stack2.pop();
	return r_value;
}


/*
������������ջʵ��һ�����С�����������ʵ��ջ��ջ���������£��ֱ�ʵ��ջ��push()������topAnddelete()������
���������ջ�Ķ��������ɾ��������ջ��ֵ���Ĳ���
ʱ�䣺2019-07-31 20:27
������CStack
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
void CStack<T>::appendTail(const T& node)  //����ѡ������һ�����н�����ջ����
{
	queue1.push(node);
}

template <class T>
T CStack<T>::topAnddelete()
{
	if (queue1.empty() && queue2.empty())
	{//��Ϊ���׳��쳣
		throw exception("the stack is empty");	
	}
	else if (!queue1.empty() && queue2.empty())
	{//queue1��Ϊ�գ�queue2Ϊ��
		while (queue1.size() > 1)
		{
			 T value = queue1.front();
			 queue2.push(value);
			 queue1.pop();
		}
		T r_value = queue1.front();  //��ʱ����ֻʣ�ս�����Ԫ��
		queue1.pop();
		return r_value;
	}
	else
	{//queue2��Ϊ�գ�queue1Ϊ��
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