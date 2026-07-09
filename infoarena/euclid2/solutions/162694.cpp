#include <iostream>
using namespace std;

inline int gcd(int A, int B) { return (!B ? A : gcd(B, A%B)); }

int main() {
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	int T;
	for (cin >> T; T; --T) {
		int A, B;
		cin >> A >> B;
		cout << gcd(A, B) << '\n';
	}
}