#include <fstream>
using namespace std;

ifstream is("euclid2.in");
ofstream os("euclid2.out");

int n;
long long x, y;
long long Euclid( long long a, long long b );

int main()
{
    is >> n;
    for ( int i = 1; i <= n; i++ )
    {
        is >> x >> y;
        os << Euclid( x, y ) << '\n';
    }

    is.close();
    os.close();
    return 0;
}

long long Euclid( long long a, long long b )
{
    if ( b == 0 )
        return a;
    return Euclid( b, a % b );
}
