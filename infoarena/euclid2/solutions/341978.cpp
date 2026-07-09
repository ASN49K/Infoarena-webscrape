#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int a,int b) {
	if (b == 0) return a;
	return cmmdc(b,a % b);
}

int main() {
	ifstream fin("cmmdc.in");
	ofstream fout("cmmdc.out");

	int a,b;
	fin >> a >> b;
	int c = cmmdc(a,b);
	if (c == 1) fout << 0 << endl;
	else fout << c << endl;

	fin.close();
	fout.close();
	return 0;
}