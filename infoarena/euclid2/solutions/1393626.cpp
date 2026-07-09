#include <fstream>
#include <iostream>
#include <utility>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main(int argc, char *argv[])
{
 	freopen("euclid2.in", "r", stdin);
 	freopen("euclid2.out", "w", stdout);
      
	int n, a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", gcd(a, b));
	}
	return 0;
}
