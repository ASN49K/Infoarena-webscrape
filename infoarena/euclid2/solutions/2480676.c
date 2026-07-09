#include <stdio.h>
#include <stdlib.h>
long euclid(long a, long b)
{
	long r;
	while(b)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int main ()
{ 
	long n , i , x , y;
	
	freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
	
	scanf("%ld", &n);
	
	for (i = 0; i < n; i ++ ) {
		scanf( "%ld%ld" , &x , &y ) ;
		printf( "%ld\n" , euclid( x , y ) );

	}
	
	
	return 0;
}