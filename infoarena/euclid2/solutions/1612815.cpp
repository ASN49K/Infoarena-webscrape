#include <iostream>
#include <fstream>
#include <stdlib.h>


using namespace std;

int cmmdc(int a, int b) {
	while (a != b) {
		if (a > b) 
			a = a - b;
		else 
			b = b - a;
	}
	return a;

}

int main() {

	int T, i, a, b;

	ifstream file1("euclid2.in");
	ofstream file2("euclid2.out");

	file1 >> T;

	for (i = 0; i < T; ++i) {
		file1 >> a >> b;
		file2 << cmmdc(a, b) << "\n";
	}

	file1.close();
	file2.close();

}