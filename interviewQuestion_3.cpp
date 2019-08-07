/*
��Ŀ���������ظ�������
���ߣ�������
ʱ�䣺2019-07-20 13:41
�ļ�����interviewQuestion_3.cpp
*/
#include<iostream>
#include<limits.h>

using namespace std;

/*
��������һ������Ϊn����������������ֶ���0~n-1�ķ�Χ�ڡ�������ĳЩ�������ظ��ģ����ǲ�֪���м��������ظ��ˣ�
Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡����磬������볤��Ϊ7,������{2,3,1,0,2,5,3}��
��ô��Ӧ��������ظ�������2����3
ʱ�䣺2019-07-20 13:41
��������findRepeatNumber
*/

//�±������һһ��Ӧ������Ӧ����е��������������м���Ӧ�±���ڵ����ݺ͵��������Ƿ���ȣ�������ظ�
bool findRepeatNumber(int arr[], int length, int* duplication)
{
	if (arr == NULL && length <= 0)
	{
		return false;
	}

	//�����ڼ���Ļ�����
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
��������һ������Ϊn+1����������������ֶ���1~n��Χ�ڣ�����������������һ���������ظ��ġ�
	 ���ҳ�����������һ���ظ������֣����ǲ����޸����顣���磬������볤��Ϊ8������{2,3,5,4,3,2,6,7}��
	 ��ô��Ӧ��������ظ�������2��3
ʱ�䣺2019-07-20 16:04
��������findRepeatNumber1
*/

/*
����:
1.���ֲ���
2.���ҵ�ͬʱ���м���
*/

//ͳ�Ʒ�Χ�����ֳ��ֵĴ���������1~3����ͳ�����������г���1~3֮�����ݵĴ���
int countRange(const int* arr, int length, int start, int end)
{
	if (arr == NULL)
	{
		return 0;
	}

	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] >= start && arr[i] <= end)   //������Ҫ��ķ�Χ��
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
				break;  //������
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
//		cout << "�������ظ�����"<< endl;
//	}
//
//	return 0;
//}

