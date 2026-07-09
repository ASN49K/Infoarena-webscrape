#include <stdio.h>
#include <stdlib.h>

int euclid2( int a, int b )
{
	int c = a % b;
	if ( c == 0 )
		return b;
	else
		return euclid2( b, c );
}

int main()
{
	FILE *fin, *fout;
	int n, a, b;
	fin = fopen( "euclid2.in", "rt" );
	fout = fopen( "euclid2.out", "wt" );

	fscanf( fin, "%i", &n );
	
	for( ;n > 0; --n )
	{
		fscanf( fin, "%i %i", &a, &b );
		fprintf( fout, "%i\n", euclid2( a, b ) );
	}
	
	fclose( fout );
	fclose( fin );
	return 0;
}