#include <fstream>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#define N_MAX 1025

using namespace std;
typedef unsigned short int usint;

usint v[3][N_MAX], CMLSC[N_MAX][N_MAX];

int main()
{
	usint i, j, k;
	ifstream in( "cmlsc.in" );
	ofstream out( "cmlsc.out" );

	in>>v[0][0]>>v[1][0];
	for( i=1; i <= v[0][0]; ++i )
		in>>v[0][i];
	for( j=1; j <= v[1][0]; ++j )
		in>>v[1][j];
	for( i=1; i <= v[0][0]; ++i )
		for( j=1; j <= v[1][0]; ++j )
		{
			if( v[0][i] == v[1][j] )
				CMLSC[i][j]=1+CMLSC[i-1][j-1];
			else CMLSC[i][j]= CMLSC[i-1][j] >= CMLSC[i][j-1] ? CMLSC[i-1][j] : CMLSC[i][j-1];
		}
	k=v[2][0]=CMLSC[v[0][0]][v[1][0]];
	for( i=v[0][0], j=v[1][0]; i && j; )
		if( v[0][i] == v[1][j] )
			v[2][k]=v[0][i], --i, --j, --k;
		else if( CMLSC[i-1][j] >= CMLSC[i][j-1] )
				--i;
			else --j;
	
	out<<v[2][0]<<'\n';
	for( i=1; i <= v[2][0]; ++i )
		out<<v[2][i]<<' ';
	out<<'\n';

	return EXIT_SUCCESS;
}
