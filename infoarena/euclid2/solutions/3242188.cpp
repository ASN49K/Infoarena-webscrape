#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in.txt");
ofstream fout("euclid2.out.txt");

int main() {
	int a, b, temp;

	fin >> a >> b;
	while (b != 0) {
		temp = b;
		b = a % b;
		a = temp;
	}
	fout<<a;
	fin.close();
	fout.close();
	return 0;
}