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
	// ����(�ˬd�GP1����, �j�p, ����)
	int shift(int p1, int p2) {
		// P1�ܤ֭n���F��
		if (p[p1].size() > 0) {
			// �t��P2�j��P1�~�i�H
			if ( (p[p2].size() <= 0) or (p[p1] < p[p2])){
				// ���i���ƤW�@�B
				if ((p1 != log[1]) or (p2 != log[0])) { 
					Pillar_TopShift(p[p1], p[p2]);
					log[0] = p1; log[1] = p2;
					return 1;
				}
				//cout << "�B�J����" << endl;
				return 0;
			}
			//cout << "�j�p����" << endl;
			return 0;
		} 
		//cout << "P1�S�F��" << endl;
		return 0;
	}
	// �յP
	int defrag() {
		if (p[1].size()>0 and p[2].size()>0) { // �W�C1.2�n���F��
			int i= p[1]-p[2];
			if (i==1){ // ���n+1 = 1�i�H�ը�2
				if (shift(2, 1)) {
					return 1;
				}
			} else if (i == -1) { // ���n-1 = 2�i�H�ը�1
				if (shift(1, 2)) {
					return 1;
				}
			} 
			//cout << "�j�p�S���s��" << endl;
			return 0;
		} 
		//cout << "�W�C����" << endl;
		return 0;
	}
	// �o�P
	int sent() {
		int m=0, a=1, b=2;
		// �������W�O���b�W3
		if (size%2 == 1) std::swap(a, b);
		// �ˬd���S���L�P(���ަ�1��2)
		if (log[1] != 0) {
			if (shift(m, a)) {
				return 1;
			} else if (shift(m, b)) {
				return 1;
			}
		}
		return 0;
	}
	// �P�Ȯt[��]
	int adju_odd() {
		int b=-1, s=-1;
		//��j��
		if (p[1] > p[2]) {
			b=1; s=2;
		} else {
			b=2; s=1;
		}
		// �p��(�����ƴN�j���^)
		if (shift(s, b)) { 
			return 1;
		} else if (shift(b, 0)) { 
			return 1;
		}
		return 0;
	}
	// �P�Ȯt[��]
	int adju_even() {
		int b=-1, s=-1;
		//��j��
		if (p[1] > p[2]) {
			b=1; s=2;
		} else {
			b=2; s=1;
		}
		// �p���^(�����ƴN�j���^)
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
			// �յP
			if (defrag()) {
				print("defrag", step);
			}
			// �o�P
			else if (sent()) {
				print("sent", step);
			}
			// �P�Ȯt��
			else if (abs(p[1]-p[2]) % 2 == 0) {
				adju_even();
				print("adju_even", step);
			}
			// �P�Ȯt��
			else if (abs(p[1]-p[2]) % 2 == 1) {
				adju_odd();
				print("adju_odd", step);
			}
		}
	}
private:
	size_t size;
	size_t step_min;
	Pillar p[3];
	int log[2]{-1, -1};
};