#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
 

int ASC(int a, int b) {
	if (b == 0) {
		return a;
	}
	return ASC(b, a%b);
}

int main() {
	
	int T, a, b;
	fin >> T;
	for (int i = 1; i <= T; i++) {
		fin >> a >> b;
		fout << ASC(a, b) << "\n";
	}

	return 0;
}
