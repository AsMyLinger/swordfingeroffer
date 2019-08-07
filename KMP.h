#include<iostream>
#include<string>
#include<vector> 
using namespace std;


//BF�㷨
int match(const string& target, const string& pattern)
{
	int target_length = target.size();        //Ŀ���ִ�
	int pattern_length = pattern.size();      //ģʽ
	int target_index = 0; int pattern_index = 0; 

	while (target_index < target_length && pattern_index < pattern_length) 
	{ 
		if (target[target_index] == pattern[pattern_index]) 
		{ 
			++target_index; 
			++pattern_index; 
		} 
		else
		{ 
			target_index = target_index-pattern_index + 1;   //Ŀ���ִ����˵�ԭ����ʼƥ���λ��+1��������ʧ���λ�ü�ȥģʽ���Ѿ�ƥ���λ��+1
			pattern_index = 0;                     //ģʽ�Ӵ����˵�0
		} 
	} 

	if (pattern_index == pattern_length) 
	{ 
		return target_index - pattern_length; 
	}
	else
	{ 
		return -1; 
	}
}

//ģʽ���ĸ�������
void compute_overlay(const string& pattern, int* &overlay_function)
{
	const int pattern_length = pattern.size(); 
	int index; 
	overlay_function[0] = -1;  //��ʼ��Ϊ-1
	for (int i = 1; i<pattern_length; ++i)
	{
		index = overlay_function[i - 1];    //����ǰ��ʧ��λ��k�洢Ϊ����
		while(index>=0 && pattern[i]!=pattern[index+1]) 
		{ 
			index = overlay_function[index];   //ʧ����ʼ���ˣ�index��¼���˵�λ��
		} 
		if(pattern[i]==pattern[index+1])     //�ַ�����ƥ��
		{
			overlay_function[i] = index + 1;
		}
		else       //index < 0
		{ 
			overlay_function[i] = -1; 
		} 
	} 
}

int kmp_find(const string& target, const string& pattern) 
{
	const int target_length = target.size(); 
	const int pattern_length = pattern.size(); 
	int * overlay_value = new int[pattern_length]; 
	
	compute_overlay(pattern, overlay_value);

	int pattern_index = 0; 
	int target_index = 0; 

	while (pattern_index<pattern_length && target_index<target_length) 
	{ 
		if (target[target_index] == pattern[pattern_index]) 
		{ 
			++target_index; 
			++pattern_index; 
		} 
		else if (pattern_index == 0) 
		{ 
			++target_index;
		} 
		else
		{ 
			pattern_index = overlay_value[pattern_index - 1] + 1;
		} 
	} 
	if (pattern_index == pattern_length) 
	{
		return target_index - pattern_index; 
	}
	else 
	{ 
		return -1; 
	} 
	delete[] overlay_value; 
} 
