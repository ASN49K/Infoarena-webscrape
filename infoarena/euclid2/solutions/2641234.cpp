#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	int k, n, m, a;
	for (scanf("%d", &k); k > 0; k--)
	{
		scanf_s("%d %d", &n, &m);
		while (m != 0) {
			a = m;
			m = n % m;
			n = a;
		}
		printf("%d\n", a);
	}
	return 0;
}
