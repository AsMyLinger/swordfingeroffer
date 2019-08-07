#include<iostream>
#include<string>
#include<vector> 
using namespace std;


//BF算法
int match(const string& target, const string& pattern)
{
	int target_length = target.size();        //目的字串
	int pattern_length = pattern.size();      //模式
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
			target_index = target_index-pattern_index + 1;   //目的字串回退到原来开始匹配的位置+1，即现在失配的位置减去模式串已经匹配的位置+1
			pattern_index = 0;                     //模式子串回退到0
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

//模式串的覆盖数组
void compute_overlay(const string& pattern, int* &overlay_function)
{
	const int pattern_length = pattern.size(); 
	int index; 
	overlay_function[0] = -1;  //初始化为-1
	for (int i = 1; i<pattern_length; ++i)
	{
		index = overlay_function[i - 1];    //将先前的失配位置k存储为索引
		while(index>=0 && pattern[i]!=pattern[index+1]) 
		{ 
			index = overlay_function[index];   //失配则开始回退，index记录回退的位置
		} 
		if(pattern[i]==pattern[index+1])     //字符串相匹配
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
