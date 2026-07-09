#include <iostream>
#include <fstream>
using namespace std;

ofstream out ("euclid2.out");
ifstream in ("euclid2.in");

unsigned int gcd(unsigned int a, unsigned int b) {
	if (b == 0) {
		return a;
	}
	else
		return gcd(b, a%b);
}

int main() {
	char thing[100];
	int pereche;
	in >> pereche;
	unsigned int a, b;
	while (pereche) {
		in >> a;
		in >> b;
		out << gcd(a, b) << '\n';
		pereche--;
	}
	return 0;
}