#include <bits/stdc++.h>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main() {

	int t; int n;
	fin >> t;

	for(int i = 1; i <= t; ++i) {

		fin >> n;

		int xorSum = 0;

		while(n--) {

			int x; fin >> x;

			xorSum = xorSum xor x;
		}

		if(xorSum) fout << "DA" << '\n';
		else fout << "NU" << '\n'; 
	}
}