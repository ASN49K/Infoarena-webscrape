#include <fstream>
using namespace std;

ifstream is("euclid2.in");
ofstream os("euclid2.out");

int t, a, b;
int Cmmdc(int a, int b );

int main()
{
    is >> t;
    for ( int i = 0; i < t; ++i )
    {
        is >> a >> b;
        os << Cmmdc(a, b ) << '\n';
    }
    is.close();
    os.close();
    return 0;
}
int Cmmdc(int a, int b )
{
    if ( b == 0 )
        return a;
    int rest;
    do
    {
        rest = a % b;
        a = b;
        b = rest;
    } while( rest );
    return a;
}
