#include <iostream>
#include <algorithm>
int tests, a, b;

int cmmdc(int a, int b) {
	if (a < b) {
		std::swap(a, b);
	}

	while (b) {
		a = a % b;
		std::swap(a, b);
	}

	return a;
}

int main() {
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	std::cin >> tests;
	for (int test_no = 0; test_no < tests; test_no++) {
		std::cin >> a >> b;
		std::cout << cmmdc(a, b) << "\n";
	}
	return 0;
}