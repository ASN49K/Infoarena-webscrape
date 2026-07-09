#include <stdio.h>

int a, b;

int cmmdc (int a, int b)
{
	if (!b) return a;
	return cmmdc (a, a%b);
}

int main ()
{
	freopen ("euclid2.in", "r", stdin);
	freopen ("euclid2.out", "w", stdout);

	scanf ("%d %d", &a, &b);

	int R = cmmdc (a, b);
	printf ("%d", (int) R);
	return 0;
}