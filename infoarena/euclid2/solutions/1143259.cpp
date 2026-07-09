#include <fstream>
using namespace std;

ifstream is("euclid2.in");
ofstream os("euclid2.out");

int T, a, b;

int Euclid( int a, int b );

int main()
{
    is >> T;
    for ( int i = 0; i < T; i++ )
    {
        is >> a >> b;
        os << Euclid( a, b );
        os << '\n';
    }
    is.close();
    os.close();
    return 0;
}

int Euclid( int a, int b )
{
    if ( !b ) return a;
    return Euclid( b, a % b );
}
