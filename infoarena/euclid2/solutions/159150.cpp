# include <stdio.h>

long a, b;

void euclid ()
{
 long r;
	while ( b != 0  )
		{
			r = a % b;
			a = b;
			b = r;
		}
	printf ( "%ld\n", a);
}

void cit ()
{
 long t;
	freopen ( "euclid2.in", "r", stdin );
	freopen ( "euclid2.out", "w", stdout );
	scanf ( "%ld", &t );
	for ( long i = 0; i < t; ++ i )
	 {
		scanf ( "%ld %ld", &a, &b );
		euclid();
	 }
	fclose ( stdout );fclose ( stdin );
}

int main ()
{
	cit();
	return 0;
}