#include <fstream>
#include <cstdlib>

using namespace std;
inline int gcd( int a, int b )
{
    if( 0 == b )
        return a;
    return gcd( b, a%b );
}
int main( void )
{
    int T, a, b;
    ifstream in( "euclid2.in" );
    ofstream out( "euclid2.out" );
    for( in>>T; T; --T )
    {
        in>>a>>b;
        out<<gcd( a, b )<<'\n';
    }
    return EXIT_SUCCESS;
}
