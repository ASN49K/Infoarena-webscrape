#include <cstdio>
using namespace std;

int gcd(int a, int b)
{
		if (!b) return a;
		return gcd(b, a%b);
}


int main()
{
		freopen("euclid2.in", "r", stdin);
		freopen("euclid2.out", "w", stdout);
		int n, a, b;
		scanf("%d", &n);
		for ( ; n;n--)
		{
				scanf("%d %d", &a,&b );
				printf("%d\n", gcd(a, b));
		}
		
		return 0;
		
}

