#include <iostream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b) {
	int r;
		while (b != 0) {
			r = a % b;
			a = b;
			b = r;
		}
		return a;
	}

int main () {
	int n, x, y;

	fin >> n;
	
	for(int i = 0; i < n; i++) {
	    fin >> x >> y;
	    fout << cmmdc(x, y) << endl;
	}

	return 0;
}
