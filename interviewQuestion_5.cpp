/*
题目：替换空格
作者：郭鹏科
时间：2019-07-27 13:29
文件名：interviewQuestion_5.cpp
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"binarysearch.h"

using namespace std;
/*
描述：请实现一个函数，将一个字符串中的空格替换成“%20”。例如，
当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
时间：2019-07-27 13:37
函数名：replaceBlack
*/

void replaceBlack(char string[], int length)
{
	if (NULL == string || length <= 0)
	{
		return;
	}

	char *pcount = string;
	int blackcount = 0;
	int strlength = 0;

	while (*pcount != '\0')
	{
		if (*pcount == ' ')
		{
			++blackcount;
		}
		++strlength;  //比实际少一个字符串'\0'
		++pcount;
	}

	char *fromend = pcount + 2 * blackcount;

	while (strlength >= 0)   //'\0'多拷贝一次
	{
		if (*pcount == ' ')  //if后边不要写后置--，判断会执行这个操作
		{
			*fromend-- = '0';
			*fromend-- = '2';
			*fromend-- = '%';
			pcount--;
		}
		else
		{
			*fromend-- = *pcount--;
		}
		strlength--;
	}
}


//int main()
//{
//	char p[30] = {0};   //6
//	
//	strcpy(p, "We are  happy. "); //We%20are%20happy.%20'\0'
//
//	int length = sizeof(p)/sizeof(p[0]);
//	
//	//cout << length<< endl;
//	show(p, length);
//	replaceBlack(p, length);
//	show(p, length);
//
//	return 0;
//}

