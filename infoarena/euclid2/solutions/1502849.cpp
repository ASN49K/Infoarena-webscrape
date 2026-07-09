#include <cstdio>
using namespace std;

FILE *f = fopen("euclid2.in","r") , *g = fopen("euclid2.out","w");

int T , a , b , i;

int gcd( int x , int y )
{
	int d , aux ;

	//make x > y
	if ( x < y ) { aux = x ; x = y ; y = aux ; };

	// d = x MOD y
	d = x % y;
	while ( d )
	{
        x = y;
		y = d;
		d = x % y;
	}

	return y;
}

void read()
{
	fscanf ( f , "%d" , &T );
	for ( i = 1 ; i <= T ; i ++ )
	{
		fscanf ( f , "%d %d" , &a , &b );
		fprintf ( g , "%d\n" , gcd ( a , b ) );
	}
}

int main()
{
	read();
	return 0;
}
