#include <cstdio>
using namespace std;

int euc(long, long);

inline void citire()
{
	long T, a, b;
	freopen("euclid2.in","r",stdin); freopen("euclid2.out","w",stdout);
	scanf("%ld", &T);
	while(T--)
	{
		scanf("%ld %ld", &a, &b);
		printf("%ld \n", euc(a, b));
	}
}

int euc(long a, long b)
{
	if(!b)
		return a;
	return euc(b, a%b);
}

int main()
{
	citire();
	return 0;
}
