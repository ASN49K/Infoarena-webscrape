#include <iostream>
#include <cstdio>

using namespace std;

int T;
long long A , B;

long long cmmdc (long long a , long long b)
{
	long long r;
	
	while (b)
	{
		r = a % b;
		
		a = b;
		
		b = r;
	}
	
	return a;
}
int main ()
{
	freopen ("euclid2.in" , "r" , stdin);
	freopen ("euclid2.out" , "w" , stdout);
	
	scanf ("%d" , &T);
	
	for (; T ; --T)
	{
		scanf ("%lld %lld" , &A , &B);
		
		printf ("%lld\n" , cmmdc (A , B));
	}

	return 0;
}
