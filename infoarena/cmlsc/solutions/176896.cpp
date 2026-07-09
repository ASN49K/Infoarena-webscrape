#include <stdio.h>

#define FIN "cmlsc.in"
#define FOUT "cmlsc.out"
#define NMAX 1025

int A[NMAX][NMAX];
int S1[NMAX], S2[NMAX];
int N, M;
FILE * fin, * fout;

int MAX( int a, int b )
{
   return a > b ? a : b;
}

void Dynamic()
{
	int i, j, t;
	
	for( i = 1; i <= N; i++ )
		for( j = 1; j <= M; j++ )
		{
			if( S1[i] == S2[j] )
				A[i][j] = A[i-1][j-1] + 1;
			else 
				A[i][j] = MAX( A[i-1][j], A[i][j-1] );
		}
	
}

void Build( int i, int j )
{
	if( i > 0 && j > 0 )
	{
		if( S1[i] == S2[j])
		{
		    Build( i - 1, j - 1 );
			fprintf( fout, "%d ", S1[i]);
		}
		else 
		{
			if( A[i-1][j] == A[i][j] ) 
				Build( i - 1, j);
			else
				Build( i, j - 1);
					
		}
	}
	
}

int main()
{
	int i;
	fin = fopen( FIN, "r" );
	fout = fopen( FOUT, "w" );
	fscanf( fin, "%d%d", &N, &M );
	for( i = 1; i <= N; i++ )
		fscanf( fin, "%d", S1+i );
	for( i = 1; i <= M; i++ )
		fscanf( fin, "%d", S2+i );
	Dynamic();
	fprintf( fout, "%d\n", A[N][M] );
	Build( N, M );
	fprintf( fout, "\n");
	fclose( fin);
	fclose( fout);
	
	
}


