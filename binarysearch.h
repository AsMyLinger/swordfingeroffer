#include<iostream>

int  binarySearch(int*ar, int start, int end, int val)   //���ֲ���
{
	int left = start;
	int right = end - 1;

	while (left <= right)
	{
		int mid = ((right - left) >> 1) + left;

		if (ar[mid] == val)
		{
			return mid;
		}
		else if (val < ar[mid])
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return -1;
}

void show(char array[], int length)     //����Ĵ�ӡ����
{
	for (int i = 0; i < length; i++)
	{
		std::cout << array[i]<<"";
	}
	std::cout << std::endl;
}