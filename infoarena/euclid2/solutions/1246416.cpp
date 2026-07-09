#include <iostream>
#include <fstream>

using namespace std;

int euclid (int a, int b) {
	if (b > a) {
		int c = a;
		a = b;
		b = c;
	}
	if (a % b == 0) {
		return b;
	} else {
		int q = a/b;
		int r = a - b*q;
		return euclid (b,r);
	}
}

int main() {
	int n,a,b;

	ifstream f;
	ofstream g ("euclid2.out", ofstream::out);


	f.open("euclid2.in", ifstream::in);
		f >> n;

		while (n > 0) {
			f >> a;
			f >> b;
			g << euclid (a,b) <<'\n';
			n--;
		}
}

