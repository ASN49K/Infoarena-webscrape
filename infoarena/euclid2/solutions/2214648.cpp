#include <iostream>

using namespace std;

unsigned int euclid(unsigned int a, unsigned int b);

int main() {
	unsigned int a, b;
	unsigned int t;

	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << euclid(a, b);
		cout << '\n';
	}

	return 0;
}

unsigned int euclid(unsigned int a, unsigned int b) {
	if (a < b) {
		unsigned int temp = a;
		a = b;
		b = temp;
	}

	unsigned int r;

	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}