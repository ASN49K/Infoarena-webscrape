#include <iostream>
#include <fstream>

using namespace std;

int gcd(int a, int b) {
	if (!b)
		return a;
	return gcd(b, a % b);
}

int main() {
	ifstream cin("euclid2.in");
	ofstream cout("euclid2.out");

	int testCases;
	for (cin >> testCases; testCases; testCases--) {
		int a, b;
		cin >> a >> b;

		cout << gcd(a, b) << "\n";
	}

	return 0;
}
