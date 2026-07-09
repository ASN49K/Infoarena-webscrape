#include<cstdio>

int Best[1025][1025];//Best[i][j] = cel mai lung subs comun folosind subsecv 1...i si 1...j
int Rec[1025][1025]; //reconstituire
int V1[1025],V2[1025];//elem
int sol[1025];//solutia
int N,M;

FILE *f = fopen("cmlsc.in","r");
FILE *g = fopen("cmlsc.out","w");

inline int max(  int x,  int y )
{
	return x > y ? x : y;
}

void compute()
{

	for( int i = 1; i <= N ; ++i ) // dinamica
	{
		for( int j = 1; j <= M ; ++j )
		{	
			int Max = max ( Best[ i - 1 ][ j ] , Best[ i ][ j-1 ] );

			if ( V1[ i ] == V2[ j ] )	
				Best[ i ][ j ] = Best[i-1][j-1] + 1;
			else Best[ i ][ j ] = Max;
			
			//fprintf(g, "%d " , Best[ i ][ j ] );
		}
		
		//fprintf(g, "\n");
	}

}

void substring( )
{
	int l=N, c=M, k = 0;
	int i,j;
	while( l )
	{
		if( V1[l] == V2[c] ){ sol[ ++k ] = V1[l]; l--; c--; }

		if( Best[ l-1 ][c] > Best[l][c-1] ) l --;
		else c--;
	}

}
	

int main()
{

	
	fscanf(f,"%d %d",&N,&M);

	for( int i=1; i<=N;++i ) fscanf(f,"%d",&V1[i]);
	for( int i=1; i<=M;++i ) fscanf(f,"%d",&V2[i]);

	compute();

	substring();

	fprintf(g,"%d\n",Best[N][M]);

	for( int i = Best[N][M];i >= 1; --i ) fprintf( g,"%d ",sol[i]);
	
	return 0;
}
