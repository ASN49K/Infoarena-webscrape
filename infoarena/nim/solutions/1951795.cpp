#include<fstream>
using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main() {
	int t;
	fin >> t;
	for (int i = 1; i <= t; i++) {
		int n, s, x; s = 0;
		fin >> n;
		for (int j = 1; j <= n; j++) {
			fin >> x;
			s = s ^ x;
		}
		if (s == 0) {
			fout << "NU\n";
		}
		else {
			fout << "DA\n";
		}
	}
}