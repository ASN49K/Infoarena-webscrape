#include <iostream>

int SimpleCmmdc(int a, int b) {
	int min = 0xFFFFFF;

	if (a < b)
		min = a;
	else
		min = b;

	for (int i = min; i >= 1; i--)
	{
		if (a%i == 0 && b%i == 0)
			return i;
	}
	return 1;
}

int SubstractEuclidCmmdc(int a, int b) {
	while (a != b) {
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}

int DivideEuclidCmmdc(int a, int b) {
	int rest;
	while (b) {
		rest = a % b;
		a = b;
		b = rest;
	}

	return a;
}


int main() {
	int a, b,n;
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		printf("%d\n", DivideEuclidCmmdc(a, b));
	}

	return 0;
}