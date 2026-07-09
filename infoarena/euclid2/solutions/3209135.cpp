#include <iostream>
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int n, a, b;

int euclid(int a, int b) {
	if (a == 0 || b == 0) {
		return a + b;
	}
	else {
		if (a > b) return euclid(a % b, b);
		else return euclid(a, b % a);
	}
}

int main() {
	in >> n;

	for (int i = 1; i <= n; i++) {
		in >> a >> b;

		out << euclid(a, b) << "\n";
	}
}