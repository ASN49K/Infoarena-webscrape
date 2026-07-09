#include <bits/stdc++.h>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main() {
	int T, n, x;
	fin >> T;
	while (T--) {
		fin >> n;
		int S = 0;
		for (int i = 1 ; i <= n ; ++i) {
			fin >> x;
			S ^= x;
		}
		if (S == 0)
			fout << "NU\n";
		else
			fout << "DA\n";
	}
	return 0;
}