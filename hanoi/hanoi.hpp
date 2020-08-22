#pragma once

#include <ios>
#include <vector>
#include <stack>
using std::vector;
using std::stack;

class harnoi {

public:
	harnoi(size_t size);
	void pri();
	void go();
	void move(int n1, int n2);

private:
	size_t size;
	size_t step_min;
	stack<int> hs[3];
};