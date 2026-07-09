#include<fstream>
using namespace std;

int cmmdc(int a, int b) {
	if(a%b == 0) {
		return b;
	}
	else {
		return cmmdc(b, a%b);
	}
}

int main() {
	ofstream fout("euclid2.out");
	ifstream fin("euclid2.in");
	int a, b, c;
	fin >> c;
	for(int i = 1; i <= c; i++) {
	fin >> a;
	fin >> b;
	fout << cmmdc(a, b) << "\n";
	}

	return 0;
}
