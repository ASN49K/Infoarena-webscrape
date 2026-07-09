#include <iostream>
#include <fstream>

using namespace std;

int ggt(int a, int b) {
	int t;
	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int a, b;

int main () {

	ifstream f("euclid2.in");
	ofstream g("euclid2.out");

	int t;
	f >> t;
	while (t--) {
		f >> a >> b;
		g << ggt(a, b) << endl;
	}

	return 0;
}