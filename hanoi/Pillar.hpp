#pragma once
#include <iostream>
#include <stack>
using namespace std;


class Pillar{
public:
	using dataType = int;
	Pillar(int n) {
		pusu_num(n);
	}
	Pillar(){}
public:
	void pusu_num(int n) {
		for (int i = n; i > 0; i--) {
			p.push(i);
		}
	}
	void print(string s = "") {
		cout << s;
		vector<dataType> v(p.size());
		stack<dataType> p = this->p;

		for (size_t i = 0, n = p.size(); i < n; i++) {
			v[n - i - 1] = p.top();
			p.pop();
		}

		for (auto&& i : v) {
			cout << i << ", ";
		} cout << endl;
	}
public:
	friend int Pillar_TopShift(Pillar& _p1, Pillar& _p2) {
		stack<Pillar::dataType>& p1 = _p1;
		stack<Pillar::dataType>& p2 = _p2;

		if (p1.size() > 0) { // ���n����P1���F��
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
		cout << "���ŦX���ʱ���" << endl;
		return 1;
	}
public:
	operator stack<dataType>&(){
		return p;
	}
	operator int () const{
		return p.top();
	}
private:
	stack<int> p;
};



