#include <iostream>
#include <fstream>

using namespace std;

fstream fin("euclid2.in");
ofstream fout("euclid2.out");


int euclid(int a, int b) {
	if (b == 0) {
		return a;
	}
	return euclid(b, a % b);
}
int main() {

	int n;
	fin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		fin >> a >> b;
		int c = euclid(a, b);
		fout << c<<'\n';
	}
	return 0;
}