#include <fstream>

using namespace std;

const int N = 1025;
int a [ N ], b [ N ], dp [ N ][ N ], r [ N ];

int main( ) {
    
    ifstream fin ( "cmlsc.in" );
    ofstream fout ( "cmlsc.out" );
    
    int n, m, i, j;
    
    fin >> n >> m;
    
    for ( i = 1; i <= n; i++ )
        fin >> a [ i ];
    
    for ( j = 1; j <= m; j++ )
        fin >> b [ j ];
    
    for ( i = 1; i <= n; i++ )
        for ( j = 1; j <= m; j++ )
            if ( a [ i ] == b [ j ] )
                dp [ i ][ j ] = 1 + dp[ i - 1 ][ j - 1 ];
            else
                dp [ i ][ j ] = max ( dp [ i - 1 ][ j ], dp [ i ][ j - 1 ] );
    
    fout << dp [ n ][ m ] << "\n";
    
    int k = 0;
    while ( dp [ n ][ m ] != 0 ) {
        
        if ( a [ n ] == b [ m ] ) {
            
            r [ k ] = a [ n ];
            k++;
            
            n = n - 1;
            m = m - 1;
        }
        
        else {
            
            if ( dp [ n ][ m ] == dp [ n - 1 ][ m ])
                n--;
            else
                m--;
        }
    }
    
    for ( i = k - 1; i >= 0; i-- )
        fout << r [ i ] << " ";
    
    return 0;
}

