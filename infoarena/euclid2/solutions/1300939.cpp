#include <fstream>
using namespace std;

ifstream is("euclid2.in");
ofstream os("euclid2.out");

long long int a, b
int t;

int ECD( int a, int b );

int main()
{
    is >> t;
    for ( int i = 1; i <= t; i++ )
    {
        is >> a >> b;
        os << ECD( a, b ) << '\n';
    }
    is.close();
    os.close();
    return 0;
}

int ECD( long long int a, long long int b )
{
    if ( b == 0 )
        return a;
    ECD( b, a%b );
}
