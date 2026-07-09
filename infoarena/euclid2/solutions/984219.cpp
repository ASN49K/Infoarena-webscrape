#include <fstream>
using namespace std;

ifstream is("euclid2.in");
ofstream os("euclid2.out");

int a, b;
int T;
int Euclid( int x, int y );

int main()
{
    is >> T;
    for ( int i = 0; i < T; ++i )
    {
        is >> a >> b;
        os << Euclid( a, b ) << '\n';
    }


    is.close();
    os.close();
    return 0;
}

int Euclid( int x, int y )
{
    int r;
    if ( y == 0 )
        return x;
    do
    {
        r = x % y;
        x = y;
        y = r;
    } while( r );
    return x;
}
