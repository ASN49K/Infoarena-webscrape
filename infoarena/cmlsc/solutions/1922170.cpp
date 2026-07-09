#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

ifstream fin( "cmlsc.in" );
ofstream fout( "cmlsc.out" );

int A[1050],B[1050],D[1050][1050],i,j,n,m;

void solve( int x, int y )
{
    while( x > 0 && D[ x - 1 ][ y ] == D[ x ][ y ] ) x--;
    while( y > 0 && D[ x ][ y - 1 ] == D[ x ][ y ] ) y--;

    if( x == 0 && y == 0 )
        return;

    solve( x - 1 , y - 1 );

    fout<<A[ x ]<<' ';
}

int main()
{

    fin>>n>>m;
    for( i = 1 ; i <= n ; i++ )
        fin>>A[ i ];
    for( j = 1 ; j <= m ; j++ )
        fin>>B[ j ];
    for( i = 1 ; i <= n ; i++ )
    {
        for( j = 1 ; j <= m ; j++ )
        {
            if( A[ i ] == B[ j ] )
                D[ i ][ j ] = D[ i - 1 ][ j - 1 ] + 1;
            else
                D[ i ][ j ] = max( D[ i - 1 ][ j ] , D[ i ][ j - 1 ] );
        }
    }
    fout<<D[ n ][ m ]<<'\n';
    solve( n , m );

return 0;
}
