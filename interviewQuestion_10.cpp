/*
��Ŀ��쳲���������
���ߣ������ƣ�
ʱ�䣺2019-07-31 21:31
�ļ�����interviewQuestion_10.cpp
*/

#include<iostream>
#include<vector>
using namespace std;

/*
��������쳲��������еĵ�n�дһ������������n,��쳲��������еĵ�n�
ʱ�䣺2019-07-31 20:27
������fibonacci
*/

long long fibonacci(unsigned int n)    //�ݹ�
{
	if (n <= 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

long long fibonacci1(long long a, long long b, unsigned int n)    //�ݹ��Ż�
{
	if (n >= 2)
	{
		return fibonacci1(a + b, a, n - 1);//�����μ���Ľ�����ϴμ���Ľ����Ϊ����������һ�μ����У��Լ����ظ����㡣���ķ���
	}

	if (n == 0)
	{
		return b;
	}
	return a;
}

long long fibonacci2(unsigned int n, vector<long long> &memory)    //�ݹ�
{	
	if (n <= 0)
	{
		memory[n] = 0;
	}
	if (n == 1)
	{
		memory[n] = 1;
	}
	else
	{
		if (memory[n] == -1)
		{
			memory[n] = fibonacci2(n - 1, memory) + fibonacci2(n - 2, memory);
		}
	}
	return memory[n];
}

long long fibonacci3(unsigned int n)   //�ǵݹ�
{
	int result[] = {0, 1};
	if (n < 2)
	{
		return result[n];
	}

	long long fibNMiunsOne = 0;
	long long fibNMiunsTwo = 1;
	long long fibN = 0;

	for (unsigned int i = 2; i <= n; i++)
	{
		fibN = fibNMiunsOne + fibNMiunsTwo;
		fibNMiunsOne = fibNMiunsTwo;
		fibNMiunsTwo = fibN;
	}
	return fibN;
}

int main()
{
	int n = 35;
	vector<long long> memory(n + 1, -1);

	cout << fibonacci(35) << endl;
	cout << fibonacci1(1, 0, 35) << endl;
	cout << fibonacci2(n, memory) << endl;

	cout << fibonacci3(35) << endl;

	return 0;
}

