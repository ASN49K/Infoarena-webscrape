#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int n, t, x, s;
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		s = 0;
		cin >> t;
		for (int j = 0; j < t; ++j) {
			cin >> x;
			s = x ^ s;
		}
		if (s == 0) {
			fout << "NU\n";
		} else {
			fout << "DA\n";
		}
	}

	return 0;
}