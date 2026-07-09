#incldue <fstream.h>

long a, b, T;
ifstream fin( "euclid2.in" );
ofstream fout( "euclid2.out" );

long cmmdc( long x, long y );

int main()
{
	fin >> T;
	for( long i = 1; i <= T; i++ );
	{
		fin >> a >> b;
		fout << cmmdc( a, b ) << '\n';
	}
	fin.close();
	fout.close();
	return 0;
}

long cmmdc( long x, long y )
{
	long r;
	while( y )
	{
		r = x%y;
		x = y;
		y = r;
	}
	return x;
}
