#include <cstdio>
using namespace std;

inline int next_int() {
	int d;
	scanf("%d", &d);
	return d;
}

int gcd(int a, int b) {
	return a == 0 ? b : gcd(b % a, a);
}

int main() {
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	int T = next_int();
	while (T--) {
		int a = next_int();
		int b = next_int();
		printf("%d\n", gcd(a, b));
	}
	return 0;
}
