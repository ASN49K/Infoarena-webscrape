// #include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main() {
	int t; in >> t;

	for (int i = 0; i < t; i++) {
		int a, b; in >> a >> b;

		while (a != 0) {
			int r = b % a;
			b = a;
			a = r;
		}
		
		out << b << "\n";
	}
	return 0;
}
