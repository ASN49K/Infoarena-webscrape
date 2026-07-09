#include <stdio.h>

unsigned long int A, B, T;

unsigned long int gcd(unsigned long int a, unsigned long int b)
{
	if (!b) return a;
	return gcd( b, a%b);
}

int main()   
{   
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	
	scanf("%uld", &T);
	
	for(; T; --T)
	{
		scanf("%uld %uld", &A, &B);
		prinft("%uld\n", gcd( A, B));
	}
	
	return 0;
}