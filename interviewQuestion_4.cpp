/*
��Ŀ����ά�����еĲ���
���ߣ�������
ʱ�䣺2019-07-20 13:41
�ļ�����interviewQuestion_4.cpp
*/

#include<iostream>

using namespace std;

/*
��������һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
ʱ�䣺2019-07-24 11:29
��������findInTwoDimArray
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
��������һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
ʱ�䣺2019-07-24 11:29
��������findInTwoDimArrayWithBinary
��ע�����Ҹ�Ϊ���ֲ���
*/


bool findInTwoDimArrayWithBinary(int* matrix, int rows, int colum, int number)
{
	bool found = false;

	if (NULL != matrix && rows > 0 && colum > 0)
	{
		//��������Ͻ��±�
		int row = 0;
		int col = colum - 1;

		//�еĶ��ֲ��ұ߽�
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
			else if (number > matrix[row*colum + mid])  //������ڣ����������
			{
				if (left == mid && right == mid)   //�鵽��һ������number��
				{
					++row;
					col = mid;    //��Ժ��Ѳ飬�ٴ�ǰ�����
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
				if (left == mid)   //�鵽��һ������number��
				{
					++row;
					col = mid - 1;  //��Դ�ǰ�飬�ٲ��
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
//		cout << "���ݴ���"<< endl;
//	}
//	else
//	{
//		cout << "��������"<< endl;
//	}
//}


