#include <fstream>
#include <iostream>
using namespace std;

int cmmdc(int a, int b) {
	int c;
	while(b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	fstream input("euclid2.in", ios_base::in);
	fstream output("euclid2.out", ios_base::out);
	int nr, a, b;
	input >> nr;
	for(int i = 0; i < nr; i++) {
		input >> a >> b;
		output << cmmdc(a, b) << "\n";
	}
	output.close();
	input.close();
}