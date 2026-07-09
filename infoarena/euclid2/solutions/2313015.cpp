#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
 
 

int main() { 

	int a, b, c, x;

	fin >> x >> a >> b;
	for (int i = 1; i <= x; i++) {
		while (b != 0) {
			c = a % b;
			a = b;
			b = c;
		}
		fout << a << "\n";
	}

	return 0;
}
