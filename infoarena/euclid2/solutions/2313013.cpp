#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
 
 

int main() {
	int nr1, nr2, T,re;
	fin >> T;
	fin >> n1 >> nr2;
	for (int i = 0; i <= T; i++) {
		while (n2 != 0) {
			re = nr1 % nr2;
			nr1 = nr2;
			nr2 = re;

		}
		fout << nr1 << "\n";

	}
	 
	return 0;
}
