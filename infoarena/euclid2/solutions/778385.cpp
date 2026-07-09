
#include <cstdio>

inline unsigned int gcd (unsigned int a, unsigned int b)
{
	unsigned int r(a % b);
	while (r)
	{
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int main (void)
{
	std::freopen("euclid2.in","r",stdin);
	std::freopen("euclid2.out","w",stdout);
	unsigned int t,a,b;
	std::scanf("%u",&t);
	do
	{
		std::scanf("%u%u",&a,&b);
		std::printf(gcd(a,b));
		--t;
	}
	while (t);
	std::fclose(stdin);
	std::fclose(stdout);
	return 0;
}

