#include <iostream>
#include <cmath>
#include <stack>
#include <string>
#include "hanoi.hpp"
#include "Pillar.hpp"
using namespace std;


//====================================================================================
using dataType = int;
using Pillar = stack<dataType>;
// ��l�ƬW�C
void Pillar_init(Pillar& p, int n) {
	for (int i = n; i > 0; i--) {
		p.push(i);
	}
}
// ���L�W�C
void Pillar_print(Pillar p, string s="") {
	cout << s;
	vector<dataType> p0(p.size());

	for (size_t i = 0, n = p.size(); i < n; i++) {
		p0[n-i-1] = p.top();
		p.pop();
	}

	for (auto&& i : p0) {
		cout << i << ", ";
	} cout << endl;
}
// �W�C��������
int Pillar_TopShift(Pillar& p1, Pillar& p2) {
	if (p1.size() > 0){ // ���n����P1���F��
		if (p2.size() == 0) { // P2�S�F�誽����
			p2.push(p1.top());
			p1.pop();
			return 0;
		} else if (p2.size() > 0) { // P2���F��n��j�p
			if (p1.top() > p2.top()) {
				p2.push(p1.top());
				p1.pop();
				return 0;
			}
		}
	}
	//cout << "���ŦX���ʱ���" << endl;
	return 1;
}
// �W�C�����Ʀr�t
int Pillar_TopDiff(const Pillar& p1, const Pillar& p2) {
	return abs(p1.top()-p2.top());
}


void Pillar_test() {
	Pillar v1, v2, v3;
	Pillar_init(v1, 5);
	Pillar_print(v1, "v1 = ");

	Pillar_TopShift(v1, v2);
	Pillar_print(v1, "v1 = ");
	Pillar_print(v2, "v2 = ");

	Pillar_TopDiff(v1, v2);
}
//====================================================================================
void Hanoi_sent(Pillar& p) {

}
//====================================================================================
int main(int argc, char const* argv[]) {
	int len = 5; //�X�ӽL�l
	Pillar v1, v2, v3;
	Pillar_init(v1, len);

	// �p��̵u�B��
	int setup = pow(2, len)-1;


	return 0;
}
//====================================================================================
