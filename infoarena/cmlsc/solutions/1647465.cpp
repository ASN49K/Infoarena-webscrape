#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int D[1030][1030],i,j,n,m,ans,sol[1030],A[1030],B[1030];

int main()
{
    fin>>n>>m;
    for( i = 1 ; i <= n ; i++ )
        fin>>A[ i ];
    for( j = 1 ; j <= m ; j++ )
        fin>>B[ j ];
    for( i = 1 ; i <= n ; i++ )
    for( j = 1 ; j <= m ; j++ )
    {
        if( A[ i ] == B[ j ] )
            D[ i ][ j ] = D[ i - 1 ][ j - 1 ] + 1;
        else
            D[ i ][ j ] = max( D[ i - 1 ][ j ] , D[ i ][ j - 1 ] );
    }
    fout<<D[ n ][ m ]<<'\n';
    i = n;
    j = m;
    while( i > 1 || j > 1 )
    {
        if( D[ i ][ j - 1 ] == D[ i ][ j ] )
            j--;
        else if( D[ i - 1 ][ j ] == D[ i ][ j ] )
            i--;
        else
            sol[ D[ i ][ j ] ] = A[ i ],i--,j--;
    }
    for( i = 1 ; i <= D[ n ][ m ] ; i++ )
    fout<<sol[ i ]<<' ';

return 0;
}
