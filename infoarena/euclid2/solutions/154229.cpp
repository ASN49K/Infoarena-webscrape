#include <stdio.h>

long long a, b;

void citire();
void cmmdc();

int main()
{
	citire();
	cmmdc();
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
	freopen( "euclid2.in", "rt", stdin );
	freopen( "euclid2.out", "wt", stdout );

	scanf( "%lld %lld", &a, &b );
}