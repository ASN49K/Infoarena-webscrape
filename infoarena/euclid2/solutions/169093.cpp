
#include <iostream>
#include <fstream>

using namespace std;

unsigned gcd(unsigned a, unsigned b) {
	unsigned r = a % b, c;
	while(r) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int main() {
	fstream fin("euclid2.in", ios::in);
	if(!fin) {
		return 1;	
	}
	fstream fout("euclid2.out", ios::out);
	if(!fout) {
		return 2;	
	}

	unsigned n, a, b;
	fin >> n;
	for(unsigned i=0; i<n; i++) {
		fin >> a >> b;
		fout << gcd(a, b) << endl;
	}

	fout.close();
	fin.close();

	return 0;
}

