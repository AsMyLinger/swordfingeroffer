/*
题目：二维数组中的查找
作者：郭鹏科
时间：2019-07-20 13:41
文件名：interviewQuestion_4.cpp
*/

#include<iostream>

using namespace std;

/*
描述：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
时间：2019-07-24 11:29
函数名：findInTwoDimArray
*/

bool findInTwoDimArray(int* matrix, int rows, int colum, int number)
{
	bool found = false;

	if (matrix != NULL && rows > 0 && colum > 0)
	{
		int row = 0;
		int col = colum - 1;

		while (row<rows && col>=0)
		{
			if (matrix[row*colum + col] == number)
			{
				found = true;
				break;
			}
			else if (matrix[row*colum + col] > number)
			{
				--col;
			}
			else
			{
				++row;
			}
		}
	}
	return found;
}

/*
描述：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
时间：2019-07-24 11:29
函数名：findInTwoDimArrayWithBinary
备注：查找改为二分查找
*/


bool findInTwoDimArrayWithBinary(int* matrix, int rows, int colum, int number)
{
	bool found = false;

	if (NULL != matrix && rows > 0 && colum > 0)
	{
		//数组的右上角下标
		int row = 0;
		int col = colum - 1;

		//行的二分查找边界
		int left = 0;
		int right = rows - 1;

		while (row < rows && col >= 0)
		{ 
			if (number > matrix[row*colum + colum-1])
			{
				++row;
				left = 0;
			}
			else if (number < matrix[row*colum])
			{
				break;
			}

			int mid = ((right - left) >> 1) + left;
			if (number == matrix[row*colum + mid])
			{
				found = true;
				break;
			}
			else if (number > matrix[row*colum + mid])  //如果大于，则继续向后查
			{
				if (left == mid && right == mid)   //查到第一个大于number的
				{
					++row;
					col = mid;    //针对后已查，再从前往后查
					left = 0;
					right = col;
				}
				else
				{
					left = mid + 1;
				}
					
			}
			else if (number < matrix[row*colum + mid])
			{
				if (left == mid)   //查到第一个大于number的
				{
					++row;
					col = mid - 1;  //针对从前查，再查后
					left = 0;
					right = col;
				}
				else
				{
					right = mid - 1;
				}
			}
		}
	}
	return found;
}


//int main()
//{
//	int array[4][4] = {1, 2, 8, 9,
//					   2, 4, 9, 12,
//					   4, 7, 10, 13,
//	                   6, 8, 11, 15};
//
//	if (findInTwoDimArrayWithBinary(*array, 4, 4,10))
//	{
//		cout << "数据存在"<< endl;
//	}
//	else
//	{
//		cout << "查无数据"<< endl;
//	}
//}


