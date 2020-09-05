#include <iostream>
#include <cmath>
#include <stack>
#include <string>
#include "Hanoi.hpp"
using namespace std;
//====================================================================================
int main(int argc, char const* argv[]) {
	Hanoi h(4);
	h.go();
	return 0;
}
//====================================================================================
