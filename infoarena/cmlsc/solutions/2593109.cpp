#include <fstream>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

#define nmax 100005

int n, m, mat[ 1030 ][ 1030 ], i, v[ 1030 ], x, j;

void afisare( int pi, int pj )
{
    int i, j;
    for( i = pi, j = pj ; mat[ i ][ j - 1 ] == mat[ i ][ j ]; j-- );
    for ( ; mat[ i - 1 ][ j ] == mat[ i ][ j ]; i-- );
    if ( mat[ i ][ j ] != 1 )
        afisare( i - 1, j - 1 );
    fout<< v[ j ] << ' ';
}

int main ()
{
     fin >> n >> m;
     for ( i = 1; i <= n; i++ )
     {
         fin >> v[ i ];
     }
     for ( i = 1; i <= m; i++ )
     {
         fin >> x;
         for( j = 1; j <= n; j++ )
         {
             if( x == v[ j ] )
                mat[ i ][ j ] = mat[ i - 1 ][ j - 1 ] + 1;
             else
                mat[ i ][ j ] = max( mat[ i ][ j - 1 ], mat[ i - 1 ][ j ] );
         }
     }
     fout<< mat[ m ][ n ] << '\n';
     afisare( m, n );
}
