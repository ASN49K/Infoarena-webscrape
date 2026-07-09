#include <iostream>
#include <fstream>

unsigned long long gcd(unsigned long long, unsigned long long);

int main() {
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	
	unsigned T;
	unsigned long long a, b;
	
	in >> T;
	
	while (T--) {
		in >> a >> b;
		out << gcd(a, b);
	}
	
	in.close();
	out.close();
	
	return 0;
}

unsigned long long gcd(unsigned long long a, unsigned long long b) {
	if (!b) {
		return a;
	}
	return gcd(b, a % b);
}