#include<stdio.h>


int euclid(int a, int b)
{
	if (!b)
		return a;
	return euclid(b, a % b);
}


int main(void)
{
	
	FILE *f_in = freopen("euclid2.in", "rt", stdin);
	FILE *f_out = freopen("euclid2.out", "wt", stdout);

	int n;
	scanf("%d\n", &n);
	
	int a, b;
	for (; n; --n) {
		scanf("%d %d\n", &a, &b);
		printf("%d\n", euclid(a, b));
	}
}

