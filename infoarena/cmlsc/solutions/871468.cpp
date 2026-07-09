#include<stdio.h>
int lcs[1025][1025],i,k,h,n,m,d[1025],x[1025],y[1025];
int main()
{
	FILE *f,*g;
	f = fopen ( "cmlsc.in" , "r" );
	g = fopen ( "cmlsc.out" , "w" );
	fscanf( f, "%d%d" , &n ,&m );
	for( i = 1; i <= n; i++ )
		fscanf( f, "%d", &x[i] );
	for( i = 1 ;i <= m ;i++ )
		fscanf( f, "%d" , &y[i] );
	for( int k = 1; k <= n; k++ )
		for ( int h = 1; h <= m; h++ )
			if( x[k] == y[h] )
				lcs[k][h] = 1 + lcs[k-1][h-1];
			else 
				if( lcs[k - 1][h] > lcs[k][h - 1] )
					lcs[k][h] = lcs[k - 1][h];
				else 
					lcs[k][h] = lcs[k][h - 1];
	fprintf( g, "%d\n" , lcs[n][m] );
	i = 0;
	k = n;
	h = m;
	while( lcs[k][h] )
	{
		if( x[k] == y[h] )
		{
			d[ i++ ] = x[k];
			k--;
			h--;
		}
		else
			if( lcs[k][h] == lcs[k-1][h] )
				k--;
			else h--;
	}
	for( k = i - 1; k >= 0 ;k-- )
		fprintf( g, "%d ", d[k] );
	return 0;
}