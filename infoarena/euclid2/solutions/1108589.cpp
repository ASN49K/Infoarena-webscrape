#include <cstdio>

using namespace std;

long long gcd(long long a, long long b)
{
	long long r;
	while(b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int n;
    long long a, b;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
	{
		scanf("%lld%lld", &a, &b);
		printf("%lld\n", gcd(a, b));
	}
    return 0;
}
