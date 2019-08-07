/*
题目：斐波那契数列
作者：郭鹏科：
时间：2019-07-31 21:31
文件名：interviewQuestion_10.cpp
*/

#include<iostream>
#include<vector>
using namespace std;

/*
描述：求斐波那契数列的第n项。写一个函数，输入n,求斐波那契数列的第n项。
时间：2019-07-31 20:27
类名：fibonacci
*/

long long fibonacci(unsigned int n)    //递归
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

long long fibonacci1(long long a, long long b, unsigned int n)    //递归优化
{
	if (n >= 2)
	{
		return fibonacci1(a + b, a, n - 1);//将本次计算的结果和上次计算的结果作为参数传入下一次计算中，以减少重复计算。第四法则
	}

	if (n == 0)
	{
		return b;
	}
	return a;
}

long long fibonacci2(unsigned int n, vector<long long> &memory)    //递归
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

long long fibonacci3(unsigned int n)   //非递归
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

