#include <stdio.h>

long long n, a, b;

void citire();
void cmmdc();

int main()
{
    long i;

    freopen( "euclid2.in", "rt", stdin );
	freopen( "euclid2.out", "wt", stdout );

    for (i=0; i<n; i++)
    {
        citire();
        cmmdc();
    }
	return 0;
}
void cmmdc()
{
	long long r;

	while ( b != 0 )
	{
		r = a % b;
		a = b;
		b = r;
	}

	printf( "%lld", a );
}
void citire()
{
    scanf( "%lld %lld", &a, &b );
}