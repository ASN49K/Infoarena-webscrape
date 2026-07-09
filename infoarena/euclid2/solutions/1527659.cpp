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

int a, b, res;

int main () {

	ifstream f("euclid2.in");
	ofstream g("euclid2.out");

	int t;
	f >> t;
	while (t--) {
		f >> a >> b;
		res = ggt(a,b);
		g << res << "\n";
	}
	f.close();
	g.close();

	return 0;
}