#include <iostream>
#include <fstream>


using namespace std;

int main() {
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	int a, b, r, T, i = 1;

	fin >> T;
	while (i <= T) {
		fin >> a >> b;
		r = a % b;
		while (r != 0) {
			a = b;
			b = r;
			r = a % b;
		}
		
			fout << b << "\n";
		
		i++;
	}
	return 0;
}