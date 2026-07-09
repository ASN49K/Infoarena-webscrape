#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int m, n, *a, *b, *subsir, top = 0, index = 0;
	// freopen("cmlsc.in", "r", stdin);
	// freopen("cmlsc.out", "w", stdout);
	scanf("%d%d", &m, &n);
	a = new int[m];
	b = new int[n];
	for(int i = 0; i < m; ++i)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; ++i)
		scanf("%d", &b[i]);
	subsir = new int[m > n ? m : n];
	for(int i = 0; i < m; ++i)
		for(int j = index; j < n; ++j)
			if(a[i] == b[j]) {
				subsir[top++] = a[i];
				break;
			}
	printf("%d\n", top);
	for(int i = 0; i < top; ++i)
		printf("%d ", subsir[i]);
	printf("\n");
	return 0;
}