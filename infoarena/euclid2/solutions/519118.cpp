#include <stdio.h>
using namespace std;

int cmmdc(int a, int b) {
	int r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int main() {
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	int n;
	int a, b;

	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d %d", &a, &b);
		printf("%d\n", cmmdc(a, b));
	}
	return 0;
}
