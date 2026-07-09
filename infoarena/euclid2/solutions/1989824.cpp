#include<stdio.h>
#include<iostream>
#include<cstdlib>
using namespace std;

int t, a, b;

int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a%b);
}

int main()
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d%d", &a, &b);
		printf("%d\n", gcd(a, b));
	}

	//system("Pause");
	return 0;
}