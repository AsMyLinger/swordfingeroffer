/*
��Ŀ���滻�ո�
���ߣ�������
ʱ�䣺2019-07-27 13:29
�ļ�����interviewQuestion_5.cpp
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"binarysearch.h"

using namespace std;
/*
��������ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20�������磬
���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
ʱ�䣺2019-07-27 13:37
��������replaceBlack
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
		++strlength;  //��ʵ����һ���ַ���'\0'
		++pcount;
	}

	char *fromend = pcount + 2 * blackcount;

	while (strlength >= 0)   //'\0'�࿽��һ��
	{
		if (*pcount == ' ')  //if��߲�Ҫд����--���жϻ�ִ���������
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

