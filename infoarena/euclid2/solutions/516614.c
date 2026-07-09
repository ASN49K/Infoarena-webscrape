#include <stdio.h>

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
	
	for(; T; --T)
	{
		scanf("%ld %ld", &A, &B);
		printf("%ld\n", gcd( A, B));
	}
	
	return 0;
}
