#include <fstream>

using namespace std;

ifstream f ( "euclid2.in" );
ofstream g ( "euclid2.out" );

int cmmmdc(int a , int b )
{
    if ( a == b )
        return a;
    else
        if ( a > b )
            return cmmmdc( a - b , b );
        else return cmmmdc( a , b - a );
}

int main()
{
    int a , b , t ;
    f >> t;
    for ( int i = 1 ; i <= t ; i ++ )
    {
        f >> a >> b;
        g << cmmmdc( a , b ) << endl ;
    }
    return 0;
}
