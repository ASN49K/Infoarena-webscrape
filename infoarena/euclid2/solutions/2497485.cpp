#include <cstdio>
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

	scanf("%d", &tests);
	for (int test_no = 0; test_no < tests; test_no++) {
		scanf("%d%d", &a, &b);
		printf("%d\n", cmmdc(a, b));
	}
	return 0;
}