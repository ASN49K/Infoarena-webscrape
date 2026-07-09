#include <cstdio>
using namespace std;

int gcd(int A, int B) { return (!B ? A : gcd(B, A%B)); }

int main() {
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	int T;
	for (scanf("%d", &T); T; --T) {
		int A, B;
		scanf("%d %d", &A, &B);
		printf("%d\n", gcd(A, B));
	}
}