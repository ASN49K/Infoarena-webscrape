#include<stdio.h>

int cmmdc(int a, int b)
{
	if (!b) return a;
	return cmmdc(b, a%b);
}

int main()
{
	int t, a, b, i;
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "W", stdout);
	fscanf("%d", &t);

	for (i=0;i<t;i++) {
		scanf("%d %d", &a, &b);
		fprintf("%d\n", cmmdc(a,b));
	}

	return 0;
}