#include<bits/stdc++.h>
using namespace std;
int n, a, b, i;
int gcd(int a, int b)
{
	if (!b) return a;
	return gcd( b, a % b );
}
int main()
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	scanf("%d", n);
	for (i = 1; i <= n; i++) {
		scanf("%d %d", a, b);
		printf("%d", gcd(a, b));
	}
	return 0;
}
