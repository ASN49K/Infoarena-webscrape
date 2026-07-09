# include <stdio.h>

long a, b;

void euclid ()
{
 long r;
	freopen ( "euclid2.out", "w", stdout );
	while ( b != 0  )
		{
			r = a % b;
			a = b;
			b = r;
		}
	printf ( "%ld", a);
	fclose ( stdout );
}

void cit ()
{
	freopen ( "euclid2.in", "r", stdin );
	scanf ( "%ld %ld", &a, &b );
	fclose ( stdin );
}

int main ()
{
	cit();
	euclid();
	return 0;
}