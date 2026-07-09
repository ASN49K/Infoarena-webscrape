#include <fstream>
#include <iostream>
#include <utility>

using namespace std;

inline int cmmdc(int a, int b) {
	int prev_b;
	while (b != 0) {
		prev_b = b;
		b = a % b;
		a = prev_b;
	}

	return prev_b;
}

int main(int argc, char *argv[])
{
 	freopen("euclid2.in", "r", stdin);
 	freopen("euclid2.out", "w", stdout);
      
	int n, a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", cmmdc(a, b));
	}
	return 0;
}
