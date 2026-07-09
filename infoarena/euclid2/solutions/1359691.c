#include<stdio.h>


int euclid(int a, int b)
{
	if (a == b)
		return a;
	if (a > b)
		return euclid (a - b, b);
	return euclid(a, b - a);
}


int main(void)
{
	
	FILE *f_in = freopen("euclid2.in", "rt", stdin);
	FILE *f_out = freopen("euclid2.out", "wt", stdout);

	int n;
	scanf("%d\n", &n);
	
	int i = 0;
	int a, b;
	for (; i < n; i++) {
		scanf("%d %d\n", &a, &b);
		printf("%d\n", euclid(a, b));
	}
}

