#include<stdio.h>

int cmmdc(int a, int b)
{
	if (!b) return a;
	return cmmdc(b, a%b);
}

int main()
{
	int t, a, b;
	freopen("euclid2.in", "r", stdin);
	ofstream out ("euclid2.out", "W', stdout);
	scanf("%d", &t);

	for (int i=0;i<t;i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", gdc(a,b));
	}

	return 0;
}