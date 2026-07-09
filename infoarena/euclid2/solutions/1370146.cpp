#include <iostream>
#include <fstream>

using std::endl;
using std::fstream;
using std::ios;

unsigned long long gcd(unsigned long long, unsigned long long);

int main() {
	fstream in("euclid2.in", ios::in);
	fstream out("euclid2.out", ios::out);
	
	unsigned T;
	unsigned long long a, b;
	
	in >> T;
	
	while (T--) {
		in >> a >> b;
		out << gcd(a, b) << '\n';
	}
	
	out.flush();
	
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