#include <iostream>
#include <cmath>
#include <stack>
#include <string>
#include "Hanoi.hpp"
#include "Pillar.hpp"
using namespace std;
//====================================================================================
void Hanoi_sent(Pillar& p) {

}
//====================================================================================
int main(int argc, char const* argv[]) {
	// 初始化
	int len = 5;
	Pillar p1(len), p2, p3;

	// 計算最短步數
	int setup = pow(2, len)-1;

	return 0;
}
//====================================================================================
