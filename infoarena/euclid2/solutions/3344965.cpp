#include <iostream>
#include <fstream>
using namespace std;

unsigned int euclid(unsigned int a, unsigned int b) {
	while (b) {
		unsigned int temp;
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main() {
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	int nr_teste;
	fin >> nr_teste;
	for (int i = 0; i < nr_teste; i++) {
		int a, b;
		fin >> a >> b;
		fout << euclid(a, b) << endl;
	}
	return 0;
}