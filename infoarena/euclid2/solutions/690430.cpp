#include <cstdio>
#include <algorithm>



using namespace std;


int main() {
	int t, a, b;
	
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	for( scanf("%d\n", &t); t-- ; ) {
		scanf("%d %d\n", &a, &b);
		printf("%d\n", __gcd(a, b));
	}
	return 0;
}
