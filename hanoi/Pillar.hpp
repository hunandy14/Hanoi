#pragma once
#include <stack>


class Pillar{
public:
	using dataType = int;
	Pillar(int n) {
		pusu_list(n);
	}
	Pillar(){}
public:
	void pusu_list(int n) {
		for (int i = n; i > 0; i--) {
			p.push(i);
		}
	}
	void print(std::string s = "") {
		std::cout << s;
		std::stack<dataType> p = this->p;
		std::stack<dataType> t;

		for (size_t i = 0, n = p.size(); i < n; i++) {
			t.push(p.top());
			p.pop();
		}
		for (size_t i = 0, n = t.size(); i < n; i++) {
			std::cout << t.top() << ", ";
			t.pop();
		} std::cout << std::endl;
	}
public:
	void push(dataType n) {
		p.push(n);
	}
	size_t size() {
		return p.size();
	}
public:
	friend int Pillar_TopShift(Pillar& _p1, Pillar& _p2) {
		std::stack<Pillar::dataType>& p1 = _p1;
		std::stack<Pillar::dataType>& p2 = _p2;

		if (p1.size() > 0) { // 必要條件P1有東西
			p2.push(p1.top());
			p1.pop();
			return 1;
		}
		throw "p1已空";
		//cout << "不符合移動條件" << endl;
		return 0;
	}
public:
	operator std::stack<dataType>&(){
		return p;
	}
	operator dataType() const{
		if (p.size()==0) throw "堆疊內沒有數據";
		return p.top();
	}
private:
	std::stack<dataType> p;
};



