#include <stdio.h>

int cmmdc (int a, int b)
{
	if (b == 0)
		return a;
	int c;
	if (a > b)
	{
		c = a % b;
		cmmdc (b, c);
	}
	else
	{
		c = b % a;
		cmmdc (a, c);
	}
}

int main () {

freopen ("euclid2.in", "r", stdin);
freopen ("euclid2.out", "w", stdout);

int a, b, n;

scanf ("%d", &n);

for (;n > 0; n--)
{
	scanf ("%d %d", &a, &b);
	printf ("%d\n", cmmdc (a, b));
}

return 0;

}
