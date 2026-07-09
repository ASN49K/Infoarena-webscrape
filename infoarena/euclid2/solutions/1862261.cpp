#include <fstream>

using namespace std;

ifstream f ( "cmmdc.in" );
ofstream g ( "cmmdc.out" );

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
        if( cmmmdc( a , b ) == 1 )
            g << 0;
        else g << cmmmdc( a , b ) ;
    }
    return 0;
}
