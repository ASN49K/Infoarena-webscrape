#include <stdio.h>
#include <assert.h>

int main() {
	int t, n, element;
	freopen("nim.in", "r", stdin);
	freopen("nim.out", "w", stdout);
	scanf("%d", &t);
	assert(1 <= t && t <= 100);

	for (; t ; --t) {
		scanf("%d", &n);
		int xorsum = 0;
		for (int i = 0 ; i < n ; ++i) {
			scanf("%d", &element);
			xorsum = xorsum ^ element;
		}

		if (xorsum) {
			printf("DA\n");
		} else {
			printf("NU\n");
		}
	}

	return 0;
}