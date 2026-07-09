#include <fstream>

/*int cmmdc(int a, int b) {
	while (a != b) {
		if (a > b)
			a -= b;
		else 
			b -= a;
	}
	return a;
}*/

int cmmdc(int a, int b) {
	while (b > 0) {
		int r = a % b;
		a = b; b = r;
	}
	return a;
}

int main() {
	int T;
	std::ifstream fin("euclid2.in");
	std::ofstream fout("euclid2.out");
	fin >> T;

	while (T--) {
		int a, b;
		fin >> a >> b;
		fout << cmmdc(a, b) << '\n';
	}

	fin.close();
	fout.close();
}