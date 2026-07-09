#include <stdio.h>
#include <stdlib.h>

long a,b;

long euclid( long a, long b)
{
	if ( b == 0 )
		return a;
	else
		return euclid( b, a % b);
}

int main()
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	
	int T;
  
  for ( scanf("%d", &T); T > 0; T--)
  {
  
    scanf("%ld %ld", &a, &b);

    long rez = euclid(a,b);

    printf("%ld\n", rez);
  }

	return 0;
}