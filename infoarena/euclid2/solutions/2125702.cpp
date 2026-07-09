#include <fstream>

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int gcd(int a, int b) {
	int t;
	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main(void) {
	std::ifstream f("euclid2.in");
	std::ofstream o("euclid2.out");
	int T, a, b;
	f >> T;
	for (; T; T--) {
		f >> a >> b;
		if (a < b) {
			swap(&a, &b);
		}
		o << gcd(a, b) << std::endl;
	}
	return 0;
}