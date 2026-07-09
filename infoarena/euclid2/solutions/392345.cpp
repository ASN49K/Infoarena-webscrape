#include<fstream>
using namespace std;
int Cmmdc( int a, int b );
ifstream fin( "euclid2.in" );
ofstream fout( "euclid2.out" );

int main()
{
	int T;
	fin >> T;
	int a[T][2];
	
	for( int i = 0; i < T; ++i )
	{
		fin >> a[i][0] >> a[i][1];
		fout << Cmmdc( a[i][0], a[i][1] ) << '\n';
	}
	
	fin.close();
	fout.close();
}


int Cmmdc(int a, int b)
{
    if ( b == 0 ) return a;
    int rest;
    do
    {
         rest = a % b;
         a = b;
         b = rest;
    } while ( rest );    

    return a;
}
