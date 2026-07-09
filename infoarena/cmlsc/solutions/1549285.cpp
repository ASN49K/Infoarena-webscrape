#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int N[1025],M[1025],n,m,i,j,D[1025][1025],ans[1025];

int main()
{
    fin>>n>>m;

    for( i = 1 ; i <= n ; i++ )
        fin>>N[ i ];
    for( i = 1 ; i <= m ; i++ )
        fin>>M[ i ];

    for( i = 1 ; i <= n ; i++ )
    {
        for( j = 1 ; j <= m ; j++ )
        {
            if( N[ i ] == M[ j ] )
                D[ i ][ j ] = D[ i - 1 ][ j - 1 ] + 1;
            else
                D[ i ][ j ] = max( D[ i - 1 ][ j ] , D[ i ][ j - 1 ] );
        }
    }

    i = n;
    j = m;

    while( D[ i ][ j ] >= 1 )
    {
        if( N[ i ] == M[ j ] )
            ans[ D[ i ][ j ] ] = N[ i ],i--,j--;
        else
        {
            if( D[ i - 1 ][ j ] > D[ i ][ j - 1 ] )
                i--;
            else
                j--;
        }
    }

    fout<<D[ n ][ m ]<<'\n';

    for( i = 1 ; i <= D[ n ][ m ] ; i++ )
        fout<<ans[ i ]<<' ';

    return 0;
}
