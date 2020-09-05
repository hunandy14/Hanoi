#pragma once
#include "Pillar.hpp"

class Hanoi {
public:
	Hanoi(int n):size(n), step_min((int)(pow(2, n)-1.0)) {
		p[0].pusu_list(n);
	}
	void print(std::string s="", int step=-1) {
		p[0].print("[0] ");
		p[1].print("[1] ");
		p[2].print("[2] ");

		if (step>=0)
			std::cout << "[step:" << step << "]--------";
		std::cout << s << std::endl;
		std::cout << "---------------------------" << std::endl;
	}
public:
	// 移動(檢查：P1為空, 大小, 重複)
	int shift(int p1, int p2) {
		// P1至少要有東西
		if (p[p1].size() > 0) {
			// 差值P2大於P1才可以
			if ( (p[p2].size() <= 0) or (p[p1] < p[p2])){
				// 不可重複上一步
				if ((p1 != log[1]) or (p2 != log[0])) { 
					Pillar_TopShift(p[p1], p[p2]);
					log[0] = p1; log[1] = p2;
					return 1;
				}
				//cout << "步驟重複" << endl;
				return 0;
			}
			//cout << "大小不符" << endl;
			return 0;
		} 
		//cout << "P1沒東西" << endl;
		return 0;
	}
	// 組牌
	int defrag() {
		int i= p[1]-p[2];
		if (i==1){ // 正好+1 = 1可以組到2
			if (shift(2, 1)) {
				return 1;
			}
		} else if (i == -1) { // 正好-1 = 2可以組到1
			if (shift(1, 2)) {
				return 1;
			}
		}
		//cout << "大小沒有連續" << endl;
		return 0;
	}
	// 發牌
	int sent() {
		int m=0, a=1, b=2;
		// 讓完成柱保持在柱3
		if (size%2 == 1) std::swap(a, b);
		// 檢查剛剛沒收過牌(不管收1或2)
		if (log[1] != 0) {
			if (shift(m, a)) {
				return 1;
			} else if (shift(m, b)) {
				return 1;
			}
		}
		return 0;
	}
	// 牌值差[單]
	int adju_odd() {
		int b=-1, s=-1;
		//找大數
		if (p[1] > p[2]) {
			b=1; s=2;
		} else {
			b=2; s=1;
		}
		// 小換(有重複就大收回)
		if (shift(s, b)) { 
			return 1;
		} else if (shift(b, 0)) { 
			return 1;
		}
		return 0;
	}
	// 牌值差[雙]
	int adju_even() {
		int b=-1, s=-1;
		//找大數
		if (p[1] > p[2]) {
			b=1; s=2;
		} else {
			b=2; s=1;
		}
		// 小收回(有重複就大收回)
		if (shift(s, 0)){
			return 1;
		} else if (shift(b, 0)) {
			return 1;
		}
		return 0;
	}
public:
	void go() {
		print("init", 0);

		for (int i = 0; i < step_min; ++i) {
			int step = i+1;

			// 發牌
			if (sent()) {
				print("發牌", step);
			// 組牌
			} else if (defrag()) {
				print("組牌", step);
			} else {
				int diff = abs(p[1] - p[2]);
				// 牌值差雙
				if (diff % 2 == 0 and adju_even()) {
					print("牌值差雙", step);
				}
				// 牌值差單
				else if (diff % 2 == 1 and adju_odd()) {
					print("牌值差單", step);
				} else {
					throw "沒有動作";
				}
			}
		}
	}
private:
	size_t size;
	size_t step_min;
	Pillar p[3];
	int log[2]{-1, -1};
};