#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

int main() {
	ifstream iff("nim.in");
	ofstream off("nim.out");
	int N;
	iff >> N;
	while (N--) {
		int n;
		iff >> n;
		int x = 0;
		while (n--) {
			int a;
			iff >> a;
			x ^= a;
		}
		if (x) {
			off << "DA" << endl;
		}
		else {
			off << "NU" << endl;
		}
	}

	return 0;
}