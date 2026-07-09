#include <bits/stdc++.h>

int cmmdc(int a, int b) {
	return b == 0 ? a : cmmdc(b, a % b);
}

int main () {
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	
	int T; scanf("%d", &T);
	while(T-- > 0) {
		int a, b; scanf("%d%d", &a, &b);
		printf("%d\n", cmmdc(a, b));
	}
}