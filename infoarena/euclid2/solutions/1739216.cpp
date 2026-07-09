#include <fstream>
using namespace std;

ifstream is("euclid2.in");
ofstream os("euclid2.out");

int Euclid( int a, int b );

int main()
{
    int n, x, y;
    is >> n;
    for( int i = 1; i <= n; i++ )
    {
        is >> x >> y;
        os << Euclid(x, y) << '\n';
    }
    return 0;
}

int Euclid( int a, int b )
{
    if( a == 0 ) return b;
    if( b == 0 ) return a;
    if ( a % b == 0 ) return b;
    Euclid( b, a % b );
}
