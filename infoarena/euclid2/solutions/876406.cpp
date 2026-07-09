#include <fstream>
using namespace std;

ifstream is("euclid2.in");
ofstream os("euclid2.out");

int Cmmdc( int n, int m );
int a, b, t;
int main()
{
    is >> t;
    for ( int i = 0; i < t; ++i )
    {
        is >> a >> b;
        int x = Cmmdc( a, b );
        os << x << '\n';
    }

    is.close();
    os.close();
    return 0;
}

int Cmmdc( int n, int m )
{
    if ( m == 0 )
        return 1;
    int rest;
    do
    {
        rest = n % m;
        n = m;
        m = rest;
    }while ( rest );
    return n;
}





























