#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");

	int T = 0, a = 0, b = 0, r = 0;
	in >> T;
	for (int i = 1; i <= T; i++) {
		in >> a >> b;
		while (b) {
			r = a % b;
			a = b;
			b = r;
		}
		out << a << " ";
		a = 0;
		b = 0;
		r = 0;
	}
return 0;
}
