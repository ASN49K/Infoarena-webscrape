#include <fstream>

using namespace std;

int cmmdc(int a, int b) {
	if (!a)
		return b;
	return cmmdc(b % a, a);
}

int main() {
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	int T, a, b;
	fin >> T;
	while (T) {
		fin >> a >> b;
		fout << cmmdc(a, b) << "\n";
		T--;
	}
}