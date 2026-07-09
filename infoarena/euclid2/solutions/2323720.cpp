#include <fstream>

int gcd(unsigned int a, unsigned int b) {
	unsigned int t{0};

	while(b) {
		t = b;
		b = a % b;
		a = t;
	}

	return a;
}

int main() {
	std::ifstream fin("euclid2.in");
	std::ofstream fout("euclid2.out");
	unsigned int T, a, b;
	
	for (fin >> T; T; --T) {
		fin >> a >> b;
		fout << gcd(a, b) << std::endl;
	}

	return 0;
}
