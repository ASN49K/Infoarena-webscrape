#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int tPerechi, x, y;

int cmmdc(int a, int b) {
	int aux;
	while(b) {
		aux = a%b;
		a = b;
		b = aux;
	}
	return a;
}

int main() {
	fin >> tPerechi;
	for(int i = 0; i < tPerechi; i++) {
		fin >> x >> y;
		fout << cmmdc(x, y) << endl;
	}
}