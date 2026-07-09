#include <iostream>
#include <fstream>

int gcd (int a, int b) {
	if (b == 0) {
		return a;
	} else {
		return gcd (b, a % b);
	}
}

int main() {
	std::ifstream in;
	std::ofstream out;
	int num, a, b;
	
	in.open ("euclid2.in");
	out.open ("euclid2.out");

	in >> num;


	for (int i = 0; i < num; ++i) {
		in >> a;
		in >> b;
		out << gcd (a, b) << "\n";
	}

	in.close();
	out.close();
}
