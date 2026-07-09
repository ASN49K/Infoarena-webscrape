#include <cstdio>

using namespace std;

int n;
int x, y;

int cmmdc(int a, int b)
{
	if(b == 0)
	{
		return a;
	}
	else
	{
		return cmmdc(b, a % b);
	}
}

int main()
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	scanf("%d", &n);

	for(int k = 0; k < n; k++)
	{
		scanf("%d %d", &x, &y);

		printf("%d\n", cmmdc(x, y));
	}

	return 0;
}
