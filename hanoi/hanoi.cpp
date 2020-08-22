#include <iostream>
#include "hanoi.hpp"
#pragma warning(disable : 4996)

using namespace std;

harnoi::harnoi(size_t s) :
	size(s), step_min((size_t)pow(2, s)-1)
{
	int temp = size;
	for (size_t i = 0; i < size; i++)
	{
		//cout << temp << endl;
		hs[0].push(temp--);
	} cout << endl;
	//cout << hs[0].size() << endl;
}
void harnoi::go() {

}

void harnoi::move(int n1, int n2)
{
	
}

void harnoi::pri()
{
	stack<int> stack_temp = hs[0];
	cout << "stack_temp.size()=" << stack_temp.size() << endl;

	for (size_t i = 0, c= stack_temp.size(); i < c; i++)
	{
		cout << stack_temp.top() << ", ";
		stack_temp.pop();
	} cout << endl;
	cout << "stack_temp.size()=" << stack_temp.size() << endl;

}

