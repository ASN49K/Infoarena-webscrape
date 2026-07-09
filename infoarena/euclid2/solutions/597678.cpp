#include <fstream>
using namespace std;

int main () {
	int T, a, b, t;

	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");

	fin >> T;

	while (T) {
		fin >> a >> b;
		while (b) {
			t = b;
			b = a % b;
			a = t;
		}
		fout << a << endl;
		--T;
	}

	return 0;
}