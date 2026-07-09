#include <iostream>
#include <stdio.h>

using namespace std;

int mat[1030][1030];
int v[1030];

void print_mat( char mat[1030][1030], int m, int n )
{
    for( int i = 0; i <= m+1; i++ )
    {
        for( int j = 0; j <= n+1; j++ )
        {
            printf( "%d ", mat[i][j] );
        }
        printf( "\n" );
    }
}

char max( char a, char b )
{
    if( a > b )
    {
        return a;
    }
    else return b;
}

int main()
{
    FILE *f = fopen( "cmlsc.in", "r" );
    FILE *g = fopen( "cmlsc.out", "w" );
    int n, m, i, j, k;

    // Citirea datelor
    fscanf( f, "%d%d", &n, &m );
    for( i = 0; i < n; i++ )
    {
        fscanf( f, "%d", &mat[0][i+2] );
    }
    for( i = 0; i < m; i++ )
    {
        fscanf( f, "%d", &mat[i+2][0] );
    }

    // Completarea matricei
    for( i = 2; i <= m+1; i++ )
    {
        for( j = 2; j <= n+1; j++ )
        {
            if( mat[0][j] == mat[i][0] )
            {
                mat[i][j] = mat[i-1][j-1] + 1;
            }
            else
            {
                mat[i][j] = max( mat[i-1][j], mat[i][j-1] );
            }
        }
    }

    // Afisarea lungimii secventei maxime
    fprintf( g, "%d\n", mat[m+1][n+1] );

    // Afisarea unei secvente maxime
    k = 0;
    i = m+1;
    j = n+1;
    while( k != mat[m+1][n+1] )
    {
        if( mat[0][j] == mat[i][0] )
        {
            v[k] = mat[0][j];
            k++;
            i--;
            j--;
        }
        else
        {
            if( mat[i-1][j] > mat[i][j-1] )
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }

    for( i = mat[m+1][n+1] - 1; i >= 0; i-- )
    {
        fprintf( g, "%d ", v[i] );
    }
    fprintf( g,  "\n" );

    fclose( f );
    fclose( g );
    return 0;
}
