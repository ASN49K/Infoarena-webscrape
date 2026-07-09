#include <cstdio>

using namespace std;

#define fin  "euclid2.in"
#define fout "euclid2.out"

int gcd(int a,int b)
{
	if ( b == 0 )
		return a;
	return gcd(b,a%b);
}

int main()
{
	int T,a,b;

	freopen(fin,"r",stdin);
	freopen(fout,"w",stdout);	
	
	scanf("%d",&T);

	while ( T-- )
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",gcd(a,b));
	}

	return 0;
}
