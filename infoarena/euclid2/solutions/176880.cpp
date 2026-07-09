#include <stdio.h>

#define FIN "euclid2.in"
#define FOUT "euclid2.out"

using namespace std;

int cmmdc( int a, int b )
{
	int r;
	while( b )
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	FILE * fin = fopen( FIN, "r" );
	FILE * fout = fopen( FOUT, "w");
	int T, a, b;
	fscanf( fin, "%d", &T);
	while( T > 0 )
	{
		fscanf( fin, "%d%d", &a, &b);
		fprintf( fout, "%d\n", cmmdc(a,b));
		T--;
	}
	
	fclose( fin );
	fclose( fout );
		
	return 0;
}
