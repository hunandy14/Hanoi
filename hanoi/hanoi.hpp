#pragma once

#include <ios>
#include <vector>
#include <stack>
#include "Pillar.hpp"
using namespace std;


class Hanoi {

public:

private:
	size_t size;
	size_t step_min;
	Pillar p[3];
};