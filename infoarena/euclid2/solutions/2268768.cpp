#include<fstream>
#include<iostream>
using namespace std;

int euclid(int a, int b) {

	int c;

	do {
		c = a % b;
		a = b;
		b = c;
	} while (c != 0);

	return a;
}

void readDataAndCompute(ifstream &fin, ofstream &fout) {
	int n, a, b;
	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> a >> b;
		fout << euclid(a, b) << "\n";
	}
}

int main() {
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	readDataAndCompute(fin, fout);
	fin.close();
	fout.close();
	return 0;
}