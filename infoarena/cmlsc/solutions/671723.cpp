#include <fstream>
#include <iostream>
#include <cstdlib>
#include <limits>
#define N_MAX 1024

using namespace std;
typedef unsigned short int usint;

usint cmlsc[N_MAX][N_MAX], v[3][N_MAX];

inline usint _max( usint x, usint y ) { return x >= y ? x : y; }
int main( void )
{
	usint i, j, k;
	
	ifstream in( "cmlsc.in" );
	
	in>>v[0][0]>>v[1][0];
	for( i=1; i <= v[0][0]; ++i )
		in>>v[0][i];
	for( j=1; j <= v[1][0]; ++j )
		in>>v[1][j];
	for( i=1; i <= v[0][0]; ++i )
		for( j=1; j <= v[1][0]; ++j )
			if( v[0][i] == v[1][j] )
				cmlsc[i][j]=cmlsc[i-1][j-1]+1;
			else cmlsc[i][j]=_max( cmlsc[i-1][j], cmlsc[i][j-1] );
	
	k=v[2][0]=cmlsc[v[0][0]][v[1][0]];
	for( i=v[0][0], j=v[1][0]; i && j; )
		if( v[0][i] == v[1][j] )
			v[2][k--]=v[0][i--], --j;
		else if( cmlsc[i-1][j] >= cmlsc[i][j-1] )
				--i;
			 else --j;
	
	ofstream out( "cmlsc.out" );
	
	out<<v[2][0]<<'\n';
	for( k=1; k <= v[2][0]; ++k )
		out<<v[2][k]<<' ';
	out<<'\n';
		
	return EXIT_SUCCESS;
}
