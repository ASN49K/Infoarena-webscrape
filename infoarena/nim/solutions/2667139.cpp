#include <cstdio>

using namespace std;

int main() {
	freopen("nim.in", "r", stdin);
	freopen("nim.out", "w", stdout);

	int n, m, a, xorsum;
	scanf("%d", &m);
	for(int i=0; i<m; ++i) {
        scanf("%d", &n);
		xorsum = 0;
		for(int j = 1; j<=n; ++j) {
			scanf("%d", &a);
			xorsum ^= a;
		}

		if (xorsum)
			printf("DA\n");
		else
			printf("NU\n");
	}

	return 0;
}
