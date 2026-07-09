#include <fstream>

using namespace std;

int main(void) {
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");

	int T, a, b, r;

	fin >> T;

	while (T--) {
		fin >> a >> b;

		while (b) {
			r = a % b;
			a = b;
			b = r;
		}

		fout << a << "\n";
	}

	fin.close();
	fout.close();

	return 0;
}
