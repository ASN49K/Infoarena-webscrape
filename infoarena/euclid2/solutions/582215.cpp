#include <iostream>
using namespace std;

// calculam cel mai mare divizor comun
int cmmdc(int a, int b)
{
	while (b != 0) {
		b = a % b;
		a = b;
	}

	return a;
}

int main(void)
{
	int T, i;
	int a, b;

	// redirectionam intrarea si iesirea
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", cmmdc(a, b));
	}

	return 0;
}
