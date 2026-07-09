// https://infoarena.ro/problema/euclid2

// 100 puncte

#include<fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main() {
	int T;
	int a, b;
	int rest;

	fin >> T;

	for(int i = 0; i < T; i++) {
		fin >> a >> b;

		while(b != 0) {
			rest = a % b;
			a = b;
			b = rest;
		}

		fout << a << endl;
	}

	return 0;
}
