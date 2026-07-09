#include <iostream>
using namespace std;

int cmmdc(int A, int B) {
	if (B == 0) return A;
	return cmmdc(B, A%B);
}

int main() {
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	int A, B;
	cin >> A >> B;
	cout << cmmdc(A, B);
}