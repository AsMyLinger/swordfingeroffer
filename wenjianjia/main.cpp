#include"MyVector.h"
#include<iostream>

using namespace std;

int main()
{
	MyVector<int> v1;
	v1.reserve(5);
	
	for(int i=0; i<10; i++)
	{
		v1.push_back(i);
	}
	v1.show();
	
	
	return 0;
}
