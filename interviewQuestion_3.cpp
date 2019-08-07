/*
题目：数组中重复的数字
作者：郭鹏科
时间：2019-07-20 13:41
文件名：interviewQuestion_3.cpp
*/
#include<iostream>
#include<limits.h>

using namespace std;

/*
描述：在一个长度为n的数组里的所有数字都在0~n-1的范围内。数组中某些数字是重复的，但是不知道有几个数字重复了，
也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7,的数组{2,3,1,0,2,5,3}，
那么对应的输出是重复的数组2或者3
时间：2019-07-20 13:41
函数名：findRepeatNumber
*/

//下标和数据一一对应，不对应则进行调整，调整过程中检测对应下标存在的数据和调整数据是否相等，相等则重复
bool findRepeatNumber(int arr[], int length, int* duplication)
{
	if (arr == NULL && length <= 0)
	{
		return false;
	}

	//建立在假设的基础上
	for (int i = 0; i < length; i++)
	{
		if (arr[i] < 0 || arr[i] > length - 1)
		{
			return false;
		}
	}
	
	for (int i = 0; i < length; i++)
	{
		while (arr[i] != i)
		{
			if (arr[i] != arr[arr[i]])
			{
				swap(arr[i], arr[arr[i]]);
			}
			else
			{
				*duplication = arr[i];
				return true;
			}
		}
	}
	return false;
}

/*
描述：在一个长度为n+1的数组里的所有数字都在1~n范围内，所以数字中至少有一个数字是重复的。
	 请找出数组中任意一个重复的数字，但是不能修改数组。例如，如果输入长度为8的数组{2,3,5,4,3,2,6,7}，
	 那么对应的输出是重复的数字2或3
时间：2019-07-20 16:04
函数名：findRepeatNumber1
*/

/*
步骤:
1.二分查找
2.查找的同时进行计数
*/

//统计范围内数字出现的次数，比如1~3，则统计整个数组中出现1~3之内数据的次数
int countRange(const int* arr, int length, int start, int end)
{
	if (arr == NULL)
	{
		return 0;
	}

	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] >= start && arr[i] <= end)   //数据在要求的范围内
		{
			++count;
		}
	}
	return count;
}


int findRepeatNumber(const int arr[], int length)
{
	if (arr == NULL && length <= 0)
	{
		return -1;
	}

	int start = 1;
	int end = length - 1;
	while (end >= start)
	{
		int middle = ((end - start) >> 1) + start;
		int count = countRange(arr, length, start, middle);
		if (end == start)
		{
			if (count > 1)
			{
				return start;
			}
			else
			{
				break;  //不存在
			}
		}
		if (count > (middle - start + 1))
		{
			end = middle;
		}
		else
		{
			start = middle + 1;
		}
	}
	return -1;
}

//int main()
//{
//	int arr[] = {2,3,6,0,4,5,2};
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int repeatnumber = INT_MAX;
//
//	/*if(findRepeatNumber(arr, len, &repeatnumber))
//	{
//		cout << repeatnumber <<endl;
//	}*/
//	repeatnumber = findRepeatNumber(arr, len);
//	if (repeatnumber)
//	{
//		cout << repeatnumber << endl;
//	}
//	else
//	{
//		cout << "不存在重复数据"<< endl;
//	}
//
//	return 0;
//}

