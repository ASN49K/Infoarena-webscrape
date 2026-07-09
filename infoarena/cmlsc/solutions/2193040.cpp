#include <iostream>
#include <fstream>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

short n, m, i, v1[ 1030 ], v2[ 1030 ], ap[ 1030 ], k, af[ 1030 ];

int main ()
{
    fin>>n>>m;
    for ( i = 1; i <= n; i++ )
    {
        fin>>v1[ i ];
    }
    for ( i = 1; i <= m; i++ )
    {
        fin>>v2[ i ];
        ap[ v2[ i ] ] ++;
    }
    for ( i = 1; i <= n; i++ )
    {
        if ( ap[ v1[ i ] ] >= 1 )
        {
            k++;
            af[ k ] = v1[ i ];
            ap[ v1[ i ] ]--;
        }
    }
    fout<<k<<'\n';
    for ( i = 1; i <= k; i++ )
    {
        fout<<af[ i ]<<' ';
    }
}
