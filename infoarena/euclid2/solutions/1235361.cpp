#include <fstream>
using namespace std;

ifstream is("euclid2.in");
ofstream os("euclid2.out");

int n, a, b;

int DC( int a, int b );

int main()
{
    is >> n;

    for( int i = 1; i <= n; i++ )
    {
        is >> a >> b;
        os << DC( a, b );
        os << '\n';
    }

    is.close();
    os.close();
    return 0;
}

int DC( int a, int b )
{
    if ( !b ) return a;
    DC( b, a % b );
}
