#include <cstdio>
using namespace std;

int cmmdc(int a, int b)
{
	int c;
	while (b)
	{
		c = a%b;
		a = b;
		b = c;
	}
	return a;
}

int main()
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	int T, i, a, b;
	scanf("%d", &T);
	for (i=0; i<T; ++i)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", cmmdc(a, b));
	}
	return 0;
}
