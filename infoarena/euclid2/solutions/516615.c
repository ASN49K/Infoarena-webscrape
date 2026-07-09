#include <stdio.h>
#include <assert.h>

long int A, B, T;

long int gcd( long int a, long int b)
{
	if (!b) return a;
	return gcd( b, a%b);
}

int main()   
{   
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	
	scanf("%ld", &T);
	assert( 1 <= T && T <= 1000000000 );
	
	for(; T; --T)
	{
		scanf("%ld %ld", &A, &B);
		assert( 2 <= A && A <= 2000000000 );
		assert( 2 <= B && B <= 2000000000 );
		printf("%ld\n", gcd( A, B));
	}
	
	return 0;
}
