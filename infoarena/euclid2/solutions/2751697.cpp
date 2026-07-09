#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b) {
	if (!b)
		return a;
	else
		return euclid(b, a % b);
}

int main() {
	int T;
	fin >> T;
	for (int i = 1; i <= T; ++i) {
		int a, b;
		fin >> a >> b;
		fout << euclid(a, b) << "\n";
	}
	return 0;
}