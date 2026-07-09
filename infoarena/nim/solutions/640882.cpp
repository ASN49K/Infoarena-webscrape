#include <stdio.h>
#include <math.h>

long t, i, n, win, j, v;

int main() {
	freopen("nim.in", "r", stdin);
	freopen("nim.out", "w", stdout);
	
	scanf("%ld", &t);
	for (i = 1; i <= t; ++i) {
		scanf("%ld", &n);
		long win = 0;
		for (j = 1; j <= n; ++j) scanf("%ld", &v), win = win ^ v;
		if (win) printf("DA\n");
		else printf("NU\n");
	}
	return 0;
}
