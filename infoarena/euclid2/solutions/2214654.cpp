#include <stdio.h>

using namespace std;

int euclid(int& a, int& b);

int main() {
	int a, b;
	int t;

	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", euclid(a, b));
	}

	return 0;
}

int euclid(int& a, int& b) {
	if (a < b) {
		int temp = a;
		a = b;
		b = temp;
	}

	int r;

	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}